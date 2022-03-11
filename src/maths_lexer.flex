%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"
%}



D [0-9]
C [a-zA-Z]   

I ({D}+)
F ({D}+"."{D}+)
NegF "-"?{F}
NegI "-"?{I}
Fr "-"?{D}+"/"{D}+

S \"[{C}{D}]+\"



%%


[*]             { return TIMES; }
[\/]            { return DIVIDE; }
[+]             { return PLUS; }
[-]             { return MINUS; }

[(]             { return LBRACKET; }
[)]             { return RBRACKET; }

[{]             { return CLBRACKET; }
[}]             { return CRBRACKET; }

[\[]            { return SLBRACKET; }
[\]]            { return SRBRACKET; }

\&\&            { return AND; }
\|\|            {return OR;}
[\!]            {return NOT;}

[=]             { return EQUALS; }

[\&]            {return B_AND}
[\|]            {return B_OR}
[\^]            {return B_XOR}
[\~]            {return B_NOT}
\<\<            {return B_LSL}
\>\>            {return B_LSR}

"int"           { return T_INT; }
"float"         { return T_FLOAT; }
"double"        {return T_DOUBLE;}
"char"          {return T_CHAR;}
"unsigned"      {return T_UINT;}
"short"         {return T_SHORT;}
"void"			    { return T_VOID; }

"break"			    { return BREAK;}
"while"			    { return WHILE;}
"if"			      { return IF; }
"case"			    { return CASE;}
"default"		    { return DEFAULT; }


"else"			    { return ELSE;}
"continue"	    { return CONTINUE; }
"do"			      { return DO ; }
"return"		    { return RETURN;}
"for"			      { return FOR; }
"unsigned"	    { return UNSIGNED;}
"switch"		    { return SWITCH; }
"enum"			    { return ENUM; }
"typedef"		    { return TYPEDEF; }
"volatile"	    { return VOLATILE; }
"struct"		    { return STRUCT; }

sizeof          { return OP_SIZEOF; }


{NegI}                     { yylval.number=strtod(yytext, 0); return INT_LITERAL; }
{NegF}                     { yylval.number=strtod(yytext, 0); return FLOAT_LITERAL; }
[{C}\_][{C}\_0-9]*        { yylval.string=new std::string(yytext); return IDENT; }
{S}                        {yylval.wordValue = new std::string; *(yylval.wordValue) = yytext; return STRING_LITERAL;}
{Fr}                       {std::string tmp = yytext; double t1,t2; t1 =  std::stod(tmp.substr(0, tmp.find("/")), nullptr);  t2 = std::stod(tmp.substr(tmp.find("/")+1,tmp.size() ), nullptr); yylval.numberValue = t1/t2; return DOUBLE_LITERAL;}




[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
