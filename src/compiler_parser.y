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
%token INT_LITERAL
%token LBRACKET RBRACKET CLBRACKET CRBRACKET

%type <prog> FUNC PROG RETURN_STMT

%start ROOT

%%

ROOT : PROG {g_root = $1}

PROG : FUNC {}

/* only implementinf int functions */
FUNC : D_INT IDENT LBRACKET RBRACKET CLBRACKET PROG RETURN_STMT CRBRACKET {}

RETURN_STMT : RETURN INT_LITERAL {}
            | RETURN IDENT

