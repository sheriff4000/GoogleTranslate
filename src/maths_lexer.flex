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
[*]             { return T_TIMES; }
[\/]            { return T_DIVIDE; }
[+]             { return T_PLUS; }

[-]             { return T_MINUS; }

[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }


\&\&          { return T_AND; }
\|\|          {return T_OR;}
[\!]            {return T_NOT;}

[=]             { return T_EQUALS; }

[\&]            {return B_AND}
[\|]            {return B_OR}
[\^]            {return B_XOR}
[\~]            {return B_NOT}
\<\<            {return B_LSL}
\>\>            {return B_LSR}

"int"         { return D_INT; }
"float"       { return D_FLOAT; }
"double"      {return D_DOUBLE;}
"char"        {return D_CHAR;}
"unsigned"    {return D_UINT;}

"break"			{ return BREAK;}

"while"			{ return WHILE;}
"if"			{ return IF; }
"case"			{ return CASE;}
"default"		{ return DEFAULT; }
"void"			{ return VOID; }
"sizeof"		{ return SIZEOF; }
"else"			{ return ELSE;}
"continue"		{ return CONTINUE; }
"do"			{ return DO ; }


"float"			{ return FLOAT;}

"int"			{ return INT; }
"return"		{ return RETURN;}
"for"			{ return FOR; }

"unsigned"		{ return UNSIGNED;}

"switch"		{ return SWITCH; }

"enum"			{ return ENUM; }
"typedef"		{ return TYPEDEF; }

"volatile"		{ return VOLATILE; }

"struct"		{ return STRUCT; }


{NegI} { yylval.number=strtod(yytext, 0); return T_INT; }
{NegF} { yylval.number=strtod(yytext, 0); return T_FLOAT; }

[{C}\_]+[{C}\_0-9]*        { yylval.string=new std::string(yytext); return T_VARIABLE; }

{S}     {yylval.wordValue = new std::string; *(yylval.wordValue) = yytext; return T_STRING;}


{Neg}   {yylval.numberValue = std::strtod(yytext,nullptr); return Number;}
{Fr}     {std::string tmp = yytext; double t1,t2; t1 =  std::stod(tmp.substr(0, tmp.find("/")), nullptr);  t2 = std::stod(tmp.substr(tmp.find("/")+1,tmp.size() ), nullptr); yylval.numberValue = t1/t2; return T_DOUBLE;}




[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
