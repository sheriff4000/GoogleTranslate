%{
    #include "ast.hpp"
    #include <cassert>

    extern const nodePtr g_root;

    int yylex(void);
    void yyerror(const char *);
%}

%union{
    const program *prog;

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

%start ROOT

%%

ROOT : PROG {g_root = $1}

PROG : FUNC {}
            | EXPR 

EXPR : EXPR EXPR
            | LBRACKET EXPR RBRACKET {$$ = $2}
            | T_INT IDENT //declaration
            | T_INT IDENT EQUALS INT_LITERAL //declaration + assignment
            | IDENT EQUALS INT_LITERAL //this is assignment, thinking we should separate, or maybe not since assignment has a return value like an expression

/* only implementing int functions */
FUNC : T_INT IDENT LBRACKET RBRACKET CLBRACKET PROG RETURN_STMT CRBRACKET {}

RETURN_STMT : RETURN INT_LITERAL {}
            | RETURN IDENT


%%

const nodePtr g_root; // Definition of variable (to match declaration earlier)

const nodePtr parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}

