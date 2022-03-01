%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}

%token T_TIMES T_DIVIDE T_PLUS T_MINUS T_EXPONENT
%token T_LBRACKET T_RBRACKET
%token T_LOG T_EXP T_SQRT
%token T_NUMBER T_VARIABLE

%type <expr> EXPR TERM UNARY FACTOR
%type <number> T_NUMBER
%type <string> T_VARIABLE T_LOG T_EXP T_SQRT FUNCTION_NAME

%start ROOT

%left T_PLUS T_MINUS
%left T_TIMES T_DIVIDE
//%left T_EXPONENT 

%%

/* The TODO notes a are just a guide, and are non-exhaustive.
   The expectation is that you do each one, then compile and test.
   Testing should be done using patterns that target the specific
   feature; the testbench is there to make sure that you haven't
   broken anything while you added it.
*/

ROOT : EXPR { g_root = $1; }

/* TODO-3 : Add support for (x + 6) and (10 - y). You'll need to add production rules, and create an AddOperator or
            SubOperator. */

EXPR : TERM           { $$ = $1;}
     | EXPR T_MINUS EXPR {$$ = new SubOperator($1, $3);}
     | EXPR T_PLUS EXPR {$$ = new AddOperator($1, $3);}
     | T_LBRACKET EXPR T_RBRACKET { $$ = $2; }
     | EXPR T_EXPONENT EXPR {$$ = new ExpOperator($1, $3);}
     //| TERM T_PLUS TERM {$$ = new AddOperator($1, $3);}
     //| TERM T_MINUS TERM {$$ = new SubOperator($1, $3);}

/* TODO-4 : Add support (x * 6) and (z / 11). */

TERM : TERM T_TIMES TERM {$$ = new MulOperator($1, $3);}
     | TERM T_DIVIDE TERM {$$ = new DivOperator($1, $3);}
     | UNARY          { $$ = $1; }
     //| UNARY T_EXPONENT UNARY {$$ = new ExpOperator($1, $3);}

/*  TODO-5 : Add support for (- 5) and (- x). You'll need to add production rules for the unary minus operator and create a NegOperator. */
UNARY : FACTOR        { $$ = $1; }
      | T_MINUS UNARY {$$ = new NegOperator($2);} //would I need to delete the old expression subtype associated with the pointer $2?
      | UNARY T_EXPONENT UNARY {$$ = new ExpOperator($1, $3);}

/* TODO-2 : Add a rule for variable, base on the pattern of number. */
FACTOR : T_NUMBER     { $$ = new Number( $1 ); }
       | T_LBRACKET EXPR T_RBRACKET { $$ = $2; }
       | T_VARIABLE { $$ = new Variable( *($1) ); } //it's a pointer to a string, so dereference
       | T_LOG FACTOR { $$ = new LogFunction( $2 ); } //function type is derived from expression.
       | T_EXP FACTOR { $$ = new ExpFunction( $2 ); }
       | T_SQRT FACTOR { $$ = new SqrtFunction( $2 ); }
       //| FUNCTION_NAME T_LBRACKET FACTOR T_RBRACKET { $$ = new LogFunction( $3 ); } //Function constructor is protected
//function name instead of T_LOG to generalise? but then what about the different constructors?

/* TODO-6 : Add support log(x), by modifying the rule for FACTOR. */

/* TODO-7 : Extend support to other functions. Requires modifications here, and to FACTOR. */
FUNCTION_NAME : T_LOG { $$ = new std::string("log"); }
              //| T_EXP {$$ = new std::string("exp");} //not sure about this one, whether it belongs here, two exp types
              | T_SQRT {$$ = new std::string("sqrt");}

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
