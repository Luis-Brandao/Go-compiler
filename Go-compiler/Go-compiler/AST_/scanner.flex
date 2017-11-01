%{
// HEADERS
#include <stdlib.h>
#include "parser.h"

// variables maintained by the lexical analyser
int yyline = 1;
%}

%option noyywrap

%%
[ \t]+ {  }
#.*\n { yyline++; }
\n { yyline++; }

\-?[0-9]+ { 
   yylval.intValue = atoi(yytext);
   return INT; 
}
"+" { return PLUS; }
"-" { return MINUS; }
"/" { return DIV; }
"*" { return MUL; }
"%" { return REMA; }
"(" { return LEFT_P; }
")" { return RIGHT_P; }
"{" { return RIGHT_P; }
"}" { return RIGHT_P; }
"TRUE" {
	yylval.intValue = 1;
	return BOOL; 
}
"FALSE" {
	yylval.intValue = 0;
	return BOOL; 
}
"AND" {
	return AND;
}
"OR" {
	return OR;
}
"NOT" {
	return NOT;
}
"EQUALS" {
	return EQUALS;
}
"IF" {
	return IF;
}
.  { yyerror("unexpected character");
}
%%

