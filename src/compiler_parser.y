%{
    #include "ast.hpp"
    #include <cassert>

    extern const program* g_root;

    int yylex(void);
    void yyerror(const char *);
%}

%union{
    const program *prog;

}

%token IDENT RETURN
%token D_INT D_FLOAT D_DOUBLE D_CHAR D_UINT D_SHORT
%token EQUAL
%token INT_LITERAL
%token LBRACKET RBRACKET CLBRACKET CRBRACKET

%type <prog> FUNC PROG RETURN_STMT EXPR

%start ROOT

%%

ROOT : PROG {g_root = $1}

PROG : FUNC {}
            | EXPR 

EXPR : EXPR EXPR
            | LBRACKET EXPR RBRACKET {$$ = $2}
            | D_INT IDENT
            | IDENT EQUAL INT_LITERAL

/* only implementinf int functions */
FUNC : D_INT IDENT LBRACKET RBRACKET CLBRACKET PROG RETURN_STMT CRBRACKET {}

RETURN_STMT : RETURN INT_LITERAL {}
            | RETURN IDENT

