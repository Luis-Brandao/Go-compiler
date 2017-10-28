// Tokens
%token 
  INT
  BOOL  
  PLUS
  MINUS
  DIV
  MUL
  REMA
  EQUALS
  AND
  OR
  NOT

// Operator associativity & precedence
%left PLUS MINUS
%left MUL DIV REMA
%left EQUALS,AND,OR,NOT

// Root-level grammar symbol
%start program;

// Types/values in association to grammar symbols.
%union {
  int intValue;
  short int boolValue;
  Expr* exprValue;
  BoolExpr* BexprValue;
  ExprList* exprList;
}

%type <intValue> INT
%type <exprValue> expr
%type <BexprValue> boolExpr
%type <exprList> expr_list
%type <boolValue> BOOL

// Use "%code requires" to make declarations go
// into both parser.c and parser.h
%code requires {
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yylex();
extern int yyline;
extern char* yytext;
extern FILE* yyin;
extern void yyerror(const char* msg);
ExprList* root;
}

%%
program: expr_list { root = $1; }

expr_list:
	{
		$$ = NULL;
	}
    |
	expr expr_list {
		 $$ = ast_exprlist($1,$2);
	}
	|
	boolExpr expr_list {
		$$ = ast_Bexprlist($1,$2);
	}
	;
	
boolExpr:
	BOOL {
		$$ = ast_bool($1);
	}
	|
	boolExpr EQUALS boolExpr {
		$$ = ast_boolOperatios(EQUALS, $1, $2);
	}
	|
	boolExpr AND boolExpr {
		$$ = ast_boolOperation(AND, $1, $2);
	}
	|
	boolExpr OR boolExpr {
		$$ = ast_boolOperation(OR,$1,$2);	
	}
	|
	NOT boolExpr {
		$$ = ast_boolOperation(NOT,$1,$2);
	}	
	;

expr:
  INT { 
    $$ = ast_integer($1); 
  }
  | 
  expr PLUS expr { 
    $$ = ast_operation(PLUS, $1, $3); 
  }
  |
  expr MINUS expr { 
    $$ = ast_operation(MINUS, $1, $3); 
  }
  |
  expr DIV expr { 
    $$ = ast_operation(DIV, $1, $3); 
  }
  |
  expr MUL expr { 
    $$ = ast_operation(MUL, $1, $3); 
  }
  |
  expr REMA expr { 
    $$ = ast_operation(REMA, $1, $3); 
  }
  ;
%%

void yyerror(const char* err) {
  printf("Line %d: %s - '%s'\n", yyline, err, yytext  );
}

