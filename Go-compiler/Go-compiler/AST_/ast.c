// AST constructor functions

#include <stdlib.h> // for malloc
#include "ast.h" // AST header

ExprList* ast_exprlist(Expr* expr, ExprList* next) {
  ExprList* node = (ExprList*) malloc(sizeof(ast_exprlist));
  node->self.aritExpr.expr = expr;
  node->self.aritExpr.exprList = next;
  node->kind = ARIT;
  return node;
}

ExprList* ast_Bexprlist(BoolExpr* bexpr, ExprList* next) {
  ExprList* node = (ExprList*) malloc(sizeof(ast_exprlist));
  node->self.boolExpr.bExpr = bexpr;
  node->self.boolExpr.bExprList = next;
  node->kind = BOOLEAN_;
  return node;
  
}

ExprList* ast_if_statement(BoolExpr* condition, ExprList* next) {
  ExprList* node = (ExprList*) malloc(sizeof(ast_exprlist));
  node->self.ifStatment.condition = condition;
  node->self.ifStatment.exprList = next;
  node->kind = IF_STATEMENT;
  return node;
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

BoolExpr* ast_boolSingleOperand (int operator, BoolExpr* arg) {
	BoolExpr* node = (BoolExpr*) malloc(sizeof(BoolExpr));
	node->kind = E_bOPERATION;
	node->attr.op.operator = operator;
	node->attr.op.left = arg;
	node->attr.op.right = NULL;
	return node;
}

BoolExpr* ast_aritEquality(Expr* left, Expr* right) {
	BoolExpr* node = (BoolExpr*) malloc(sizeof(BoolExpr));
	node->kind = E_aritEQUALITY;
	node->attr.eq.left = left;
	node->attr.eq.right = right;
	return node;
}	
	

Expr* ast_operation (int operator, Expr* left, Expr* right) {
	Expr* node = (Expr*) malloc(sizeof(Expr));
	node->kind = E_OPERATION;
	node->attr.op.operator = operator;
	node->attr.op.left = left;
	node->attr.op.right = right;
	return node;
}
