%code requires{

    #include "ast.hpp"

    extern node *g_root;
    extern FILE *yyin;


    int yylex(void);
    void yyerror(const char *);
}

%union{
	yytokentype token;
    std::string* string;
    int number;
	char _char;
    float f_number;
	node_ptr expr;
	node_vector_ptr exprlist;
}

%token IDENTIFIER FLOAT_LITERAL INT_LITERAL STRING_LITERAL DOUBLE_LITERAL SIZEOF CHAR_LITERAL
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start ROOT


//BASICally all the ones that TURN INTO NODES
//%type <node> FUNC_DEF
%type <expr> primary_expression postfix_expression unary_expression
%type <expr> multiplicative_expression additive_expression shift_expression
%type <expr> relational_expression equality_expression and_expression
%type <expr> exclusive_or_expression inclusive_or_expression logical_and_expression
%type <expr> logical_or_expression conditional_expression assignment_expression
%type <expr> expression constant_expression

%type <expr> declaration init_declarator
%type <expr> declaration_specifiers type_specifier
%type <expr> struct_declaration //struct_specifier
%type <expr> struct_declarator declarator
%type <expr> enum_specifier enumerator direct_declarator pointer


%type <expr> parameter_declaration type_name abstract_declarator direct_abstract_declarator
%type <expr> initializer statement labeled_statement compound_statement
%type <expr> expression_statement selection_statement iteration_statement
%type <expr> jump_statement external_declaration function_definition ROOT
%type <expr> cast_expression 

%type <exprlist> translation_unit struct_declaration_list argument_expression_list
%type <exprlist> specifier_qualifier_list struct_declarator_list
%type <exprlist> enumerator_list parameter_type_list parameter_list
%type <exprlist> identifier_list initializer_list declaration_list statement_list init_declarator_list

%type <number> INT_LITERAL
%type <f_number> FLOAT_LITERAL
%type <string> IDENTIFIER STRING_LITERAL
%type <number> 	CHAR_LITERAL

%%

primary_expression
	: IDENTIFIER {$$ = new identifier($1); std::cout << *$1;} //constructing nodes and passing the values as the argument
	| FLOAT_LITERAL {$$ = new float_literal($1);}
	| INT_LITERAL {$$ = new int_literal($1);}
	| STRING_LITERAL {$$ = new string_literal(*$1);}
	| CHAR_LITERAL {$$ = new char_literal($1);}
	| '(' expression ')' {$$ = $2;}
	;

postfix_expression
	: primary_expression {$$ = $1;}
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')' {$$ = new func_call($1);}
	| postfix_expression '(' argument_expression_list ')' {$$ = new func_call($1, $3);}
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

argument_expression_list
	: assignment_expression {$$ = new_vector($1);}
	| argument_expression_list ',' assignment_expression {$1->push_back($3); $$ = $1;}
	;

unary_expression
	: postfix_expression {$$ = $1;}
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression {$$ = new size_of($2);}
	| SIZEOF '(' type_name ')' {$$ = new size_of($3);}
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression {$$ = $1;}
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression {$$ = $1;}
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression {$$ = $1; std::cout << "multiplicative created" << std::endl;}
	| additive_expression '+' multiplicative_expression {$$ = new add_op($1, $3); std::cout << "add_op created" << std::endl;}
	| additive_expression '-' multiplicative_expression {$$ = new sub_op($1, $3);}
	;

shift_expression
	: additive_expression {$$ = $1;}
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression 
	: shift_expression {$$ = $1;}
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression {$$ = $1;}
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression {$$ = $1;}
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression {$$ = $1;}
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression {$$ = $1;}
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression {$$ = $1;}
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression {$$ = $1;}
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression {$$ =$1;}
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression 
	: conditional_expression {$$ = $1;}
	| unary_expression assignment_operator assignment_expression {$$ = new assignment($1, $3);}
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression {$$ = $1;}
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'{std::cerr << "declaration with no name" << std::endl;}
	| declaration_specifiers init_declarator_list ';' {$$ = new declaration($1, $2);} //init_declarator is a list of declarators or init declarators because init declarator can be either, and the list is just a list of them
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier {$$ = $1;}
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator {$$ = new_vector($1);}
	| init_declarator_list ',' init_declarator{$1->push_back($3); $$ = $1;}
	;

init_declarator
	: declarator {$$ = $1;}
	| declarator '=' initializer  {$$ = new init_declarator($1, $3);}
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID {$$ = new specifier_type("void");} //Better to use a class, but for now just use strings
	| CHAR {$$ = new specifier_type("char");}
	| SHORT {$$ = new specifier_type("short");}
	| INT {$$ = new specifier_type("int");} //NEEDS TO BE OF TYPE: node_ptr
	| LONG {$$ = new specifier_type("long");}
	| FLOAT {$$ = new specifier_type("float");}
	| DOUBLE
	| SIGNED {$$ = new specifier_type("signed");}
	| UNSIGNED {$$ = new specifier_type("unsigned");}
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME {$$ = new specifier_type("type");}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier 
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST
	| VOLATILE
	;

declarator
	: pointer direct_declarator
	| direct_declarator {$$ = $1;}
	;

direct_declarator 
	: IDENTIFIER {$$ = new declarator(*$1);}
	| '(' declarator ')' {$$ = $2;}
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')' {$$ = new function_declarator($1, $3);}//List like int main(int a, int b)
	| direct_declarator '(' identifier_list ')' {}//List like int a,b,c = 1;
	| direct_declarator '(' ')' {$$ = new function_declarator($1); std::cout << "Function declarator created" << std::endl;}
	;//of type declarator

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list {$$ = $1;}
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration {$$ = new_vector($1);}
	| parameter_list ',' parameter_declaration {$$ = $1; $$->push_back($3);}
	;

parameter_declaration
	: declaration_specifiers declarator {$$ = new declaration($1, $2);} //declaration without a list
	| declaration_specifiers abstract_declarator //wat is abstract
	| declaration_specifiers //idek
	;

identifier_list
	: IDENTIFIER {$$ = new_vector(	new identifier($1)	);}
	| identifier_list ',' IDENTIFIER {$1->push_back( new identifier($3)); $$ = $1;}
	;

type_name
	: specifier_qualifier_list {$$ = (*$1)[0];}
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer //no idea
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement {$$ = $1;}
	| compound_statement {$$ = $1;}
	| expression_statement {$$ = $1;}
	| selection_statement {$$ = $1;}
	| iteration_statement {$$ = $1;}
	| jump_statement {$$ = $1;}
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}' {$$ = new statement_list();}
	| '{' statement_list '}' {$$ = new statement_list($2);}
	| '{' declaration_list '}' {$$ = new statement_list($2);}
	| '{' declaration_list statement_list '}' {$$ = new statement_list($2); $$->append($3);}
	;

declaration_list
	: declaration {$$ = new_vector($1);}
	| declaration_list declaration {$1->push_back($2); $$ = $1;}
	;

statement_list
	: statement {$$ = new_vector($1);}
	| statement_list statement {$1->push_back($2); $$ = $1;}
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement {$$ = new if_statement($3, $5);}
	| IF '(' expression ')' statement ELSE statement {$$ = new if_else_statement($3, $5, $7);}
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';' //{$$ = new return_stmt();}
	| RETURN expression ';' {$$ = new return_stmt($2);}
	;

translation_unit
	: external_declaration {$$ = new_vector($1);}
	| translation_unit external_declaration {$1->push_back($2); $$ = $1;}//idek don't ask maybe it works maybe it doesn't
	;
	 //of type exprlist, hence we need a vector of node_ptrs

external_declaration
	: function_definition {$$ = $1;}
	| declaration {$$ = $1;}
	;

function_definition
	: declaration_specifiers declarator compound_statement {$$ = new function_def($1, $2, $3);} //function_def(node_ptr _type, node_ptr _id, node_vector_ptr _args, std::vector<node_ptr> statements); THIS ONE
	//: declaration_specifiers declarator declaration_list compound_statement {$$ = new function_def($1, $2, $3, $4);}
	 //so int main (declaration_list (list of int a, intb etc.)) then {compound statement}
	//declaration_specifiers should be resolved just fine, int should pass through for example.
	//declarator: should pass up from identifier(if we lex it properly) up to direct_declarator then declarator, it inlcude the empty brackets like main()
	//we can ignore declaration_list for now since the below grammar doesn't include it, obv. in main() doesn't either
	//compound_statement id of type statement list and has a list of node_ptr
	
	//THIS ONE DOESN'T HAVE LIST OF ARGS, ONLY STATMENTS WHICH IS $3. idk how the overloading works tbh but should be fine.
	//we pass the specifier (rn its a string*, better to have a class, but no), we pass the declarator (ident class), and the compound statement as a vector of node_ptrs
	
	//| declarator declaration_list compound_statement
	//| declarator compound_statement 
	;
ROOT
	:translation_unit {g_root = new root($1);}

%%


// classic parser stuff - idk what it does [TO FIGURE OUT]
node *g_root;

node* parseAST(std::string filename)
{
  yyin = fopen(filename.c_str(), "r");
  if(yyin == NULL){
    std::cerr << "Couldn't open input file: " << filename << std::endl;
    exit(1);
  }
  g_root = NULL;
  yyparse();
  std::cout << "parsed g_root: " << g_root << std::endl;
  return g_root;
} 
