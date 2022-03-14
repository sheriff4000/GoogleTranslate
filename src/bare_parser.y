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

%token IDENT T_INT INT_LITERAL 
%token PROG //actual contents of a function
%token LBRACKET RBRACKET CLBRACKET CRBRACKET // types of bracket

%type <expr> FUNC_DEF


%start ROOT

%%

ROOT : FUNC_DEF {g_root = $1};

FUNC_DEF : T_INT IDENT LBRACKET RBRACKET CLBRACKET PROG CRBRACKET {$$ = new function_def($6)};


%%
// classic parser stuff - idk what it does [TO FIGURE OUT]
node *g_root;

node *parseAST(std::string filename)
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
