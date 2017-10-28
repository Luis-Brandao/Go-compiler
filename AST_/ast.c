// AST constructor functions

#include <stdlib.h> // for malloc
#include "ast.h" // AST header

ExprList* ast_exprlist(Expr* expr, ExprList* next) {
	
  ExprList* node = (ExprList*) malloc(sizeof(ast_exprlist));
  node->self.aritExpr.expr = expr;
  node->self.aritExpr.exprList = next;
  node->kind = ARIT;

}

ExprList* ast_Bexprlist(BoolExpr* bexpr, ExprList* next) {
	
  ExprList* node = (ExprList*) malloc(sizeof(ast_exprlist));
  node->self.boolExpr.bExpr = bexpr;
  node->self.boolExpr.bExprList = next;
  node->kind = BOOLEAN;
  
}
Expr* ast_integer(int v) {
  Expr* node = (Expr*) malloc(sizeof(Expr));
  node->kind = E_INTEGER;
  node->attr.value = v;
  return node;
}

BoolExpr* ast_bool(int b) {
  BoolExpr* node = (BoolExpr*) malloc(sizeof(BoolExpr));
  node->kind = E_LITERAL;
  node->attr.literal = b;
  return node;
}

BoolExpr* ast_boolOperation (int operator, BoolExpr* left, BoolExpr* right) {
	BoolExpr* node = (BoolExpr*) malloc(sizeof(BoolExpr));
	node->kind = E_bOPERATION;
	node->attr.op.operator = operator;
	node->attr.op.left = left;
	node->attr.op.right = right;
	return node;
}

Expr* ast_operation (int operator, Expr* left, Expr* right) {
	BoolExpr* node = (BoolExpr*) malloc(sizeof(BoolExpr));
	node->kind = E_OPERATION;
	node->attr.op.operator = operator;
	node->attr.op.left = left;
	node->attr.op.right = right;
	return node;
}
