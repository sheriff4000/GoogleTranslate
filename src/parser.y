%code requires{

    #include "ast.hpp"

    extern nodePtr g_root;
    extern FILE *yyin;


    int yylex(void);
    void yyerror(const char *);
}

%union{
    std::string* string;
    int number;
    nodePtr node;
}

%token IDENT RETURN
%token T_INT T_FLOAT T_DOUBLE T_CHAR T_UINT T_SHORT T_VOID SIGNED UNSIGNED T_LONG
%token EQUALS 
%token PLUS MINUS TIMES DIVIDE
%token AND OR NOT B_AND B_OR B_NOT B_LSL B_LSR B_XOR 
%token INT_LITERAL FLOAT_LITERAL STRING_LITERAL DOUBLE_LITERAL
%token LBRACKET RBRACKET CLBRACKET CRBRACKET SLBRACKET SRBRACKET
%token BREAK WHILE IF ELSE CASE DEFAULT VOID CONTINUE DO ENUM TYPEDEF VOLATILE STRUCT
%token OP_SIZEOF FOR SWITCH

%start ROOT
//BASICally all the ones that TURN INTO NODES
%type <node> FUNC_DEF
%%

ROOT : FUNC_DEF {g_root = $1;}

FUNC_DEF
        : TYPE_SPECIFIER DIRECT_DECLARATOR COMPOUND_STATEMENT {$$ = new function_def();} //direct declarator will have args but idk}

COMPOUND_STATEMENT
	: '{' '}'
	;

DIRECT_DECLARATOR
                : IDENT
                | DIRECT_DECLARATOR '(' ')'
                ;

TYPE_SPECIFIER
	: T_VOID
	| T_CHAR
	| T_SHORT
	| T_INT
	| T_LONG
	| T_FLOAT
	| T_DOUBLE
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

const node* parseAST(std::string filename)
{
  yyin = fopen(filename.c_str(), "r");
  if(yyin == NULL){
    std::cerr << "Couldn't open input file: " << filename << std::endl;
    exit(1);
  }
  g_root = NULL;
  yyparse();
  return g_root;
} 
