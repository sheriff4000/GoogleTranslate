%code requires{

    #include "ast.hpp"

    extern node *g_root;
    extern FILE *yyin;


    int yylex(void)
    void yyerror(const char *);
}

%union{
    std::string *string;
    int number;
    nodePtr expr;
}

%token IDENT RETURN
%token T_INT T_FLOAT T_DOUBLE T_CHAR T_UINT T_SHORT T_VOID
%token EQUALS 
%token PLUS MINUS TIMES DIVIDE
%token AND OR NOT B_AND B_OR B_NOT B_LSL B_LSR
%token INT_LITERAL FLOAT_LITERAL STRING_LITERAL
%token LBRACKET RBRACKET CLBRACKET CRBRACKET SLBRACKET SRBRACKET
%token BREAK WHILE IF ELSE CASE DEFAULT VOID CONTINUE DO ENUM TYPEDEF VOLATILE STRUCT
%token OP_SIZEOF

%type <prog> FUNC PROG RETURN_STMT EXPR ASSIGN


%type <expr> FUNC_DEF


%start ROOT

%%

ROOT : FUNC_DEF {g_root = $1};

FUNC_DEF
        : TYPE_SPECIFIER DIRECT_DECLARATOR {$$ = new function_def()}; //direct declarator will have args but idk}

COMPOUND_STATEMENT
	: '{' '}'
	| '{' STATEMENT_LIST '}'
	;

DIRECT_DECLARATOR
                : IDENT
                | DIRECT_DECLARATOR '(' ')'
                ;

TYPE_SPECIFIER
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	;


UNARY_OPERATOR
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

PRIMARY_EXPRESSION
                  : IDENT
                  | CONSTANT
                  | STRING_LITERAL  
                  |  '(' PRIMARY_EXPRESSION ')'
                  ;

CONSTANT :INT_LITERAL 
        | FLOAT_LITERAL 
        | STRING_LITERAL
        ;



%%


// classic parser stuff - idk what it does [TO FIGURE OUT]
node *g_root;

node *parseAST() //(std::string filename)
{
 // yyin = fopen(filename.c_str(), "r");
  //if(yyin == NULL){
    //std::cerr << "Couldn't open input file: " << filename << std::endl;
   // exit(1);
  //}
  g_root = NULL;
  yyparse();
  return g_root;
}
