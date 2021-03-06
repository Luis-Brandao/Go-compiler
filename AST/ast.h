
// AST definitions
#ifndef __ast_h__
#define __ast_h__

struct _BoolExpr {
  enum { 
    E_LITERAL,
    E_bOPERATION,
    E_aritEQUALITY
  } kind;
  union {
    int literal; // T,F
    struct { 
      int operator; // OR; AND...
      struct _BoolExpr* left;
      struct _BoolExpr* right;
    } op;
    struct {
		struct _Expr* left;
		struct _Expr* right;
	} eq;
  } attr;
};
	
// AST for expressions
struct _Expr {
  enum { 
    E_INTEGER,
    E_OPERATION
  } kind;
  union {
    int value; // for integer values
    struct { 
      int operator; // PLUS, MINUS, etc 
      struct _Expr* left;
      struct _Expr* right;
    } op; // for binary expressions
  } attr;
};


struct _ExprList {
	union{

		struct {
			struct _Expr* expr;
			struct _ExprList* exprList;
		} aritExpr;
		
		struct {
			struct _BoolExpr* bExpr;
			struct _ExprList* bExprList;
		} boolExpr;

        struct {
            struct _BoolExpr* condition;
            struct _ExprList* exprList;
        } ifStatement;
	 	
	} self;
	
	enum{
		ARIT,
		BOOLEAN_,
                IF_STATEMENT
	} kind;
};

typedef struct _BoolExpr BoolExpr;
typedef struct _ExprList ExprList;
typedef struct _Expr Expr;

// Constructor functions (see implementation in ast.c)
Expr* ast_integer(int v);
Expr* ast_operation(int operator, Expr* left, Expr* right);
BoolExpr* ast_bool(int b);
BoolExpr* ast_boolOperation(int operator, BoolExpr* left, BoolExpr* right);
BoolExpr* ast_boolEquality(BoolExpr* left, BoolExpr* right);
BoolExpr* ast_aritEquality(Expr* left, Expr* right);
BoolExpr* ast_boolSingleOperand (int operator, BoolExpr* arg);
ExprList* ast_if_statement (BoolExpr* condition, ExprList* next);
ExprList* ast_exprlist(Expr* expr, ExprList* next);
ExprList* ast_Bexprlist(BoolExpr* bexpr, ExprList* next);

#endif
