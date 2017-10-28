#include <stdio.h>
#include "parser.h"

void evalARIT(Expr* expr) {
  int result = 0;
  if (expr == 0) {
    yyerror("Null expression!!");
  }
  else if (expr->kind == E_INTEGER) {
    printf("%d", expr->attr.value); 
  } 
  else if (expr->kind == E_OPERATION) {
    printf("( ");
    evalARIT(expr->attr.op.left);
    
    switch (expr->attr.op.operator) {
    case PLUS: 
		printf(" PLUS ");
		break;	
    case MINUS:
		printf(" MINUS ");
		break;
    case DIV:
		printf(" DIV ");
		break;
    case MUL:
		printf(" MUL ");
		break;
    case REMA:
		printf(" REMA ");
		break;
    default: yyerror(" Unknown operator! ");
    }
    
    evalARIT(expr->attr.op.right);
    printf(" )");
    
  }
}


int printTree(ExprList* root) {
	if(root == NULL) return 0;
	if(root->kind == ARIT) {
		Expr* expr = root->self.aritExpr.expr;
		evalARIT(expr);
		
		//move to next expression
		root = root->self.aritExpr.exprList;
		printTree(root);
	}else if(root->kind == BOOLEAN) {
			printf("BOOL TBA");
	}
	return 0;
}

int main(int argc, char** argv) {
	
  --argc; ++argv;
  
  if (argc != 0) {
	  
    yyin = fopen(*argv, "r");
    if (!yyin) {
		
      printf("'%s': could not open file\n", *argv);
      return 1;
      
    }
    
  }
  
  if (yyparse() == 0) {
	  
    printTree(root);
    
  }
  
  return 0;

}
