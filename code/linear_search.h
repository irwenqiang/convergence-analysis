#ifndef _LINEAR_SEARCH_H_
#define _LINEAR_SEARCH_H_
#include "common.h"


// define callback evalute function
// @retval the value of object function at x.
typedef double (* func_evaluator)(
	void *instance, // user-specified object
	double *x, // the current variables
	double *g, // gradient
	int n // number of variables
);
// simplest linear search method: backtracking linear search
// @retval selected step length, negative value means failure to find a proper step length
// reference: Numerical Optimization(Jorge Nocedal,Stephen J.Wright,1999), Chapter 3, Page41.
double backtracking_linear_search(
	void *instance, // user-specified object
	func_evaluator proc_evaluate, // object-function value evaluator
	double *x, // current point
	double *xp, // backup place for x
	double *g, // current gradient
	double *p, // negative search direction, Warning, p should not equal to g, because the procedure require p unchanged but change g when call proc_evaluate
	int n, // number of varialbes
	double *fx, // current function value at x
	double c, // sufficient decrease condition threshold
	double init_step, // initial step length
	double r, // scale factor in backtracking
	int *evaluateCnt  // the counter of call obj-function evaluater
);
// guess a inital step when use linear search
// @g, gradient
// @n, number of variables
// @iter, optional, current iteration
double guess_init_step(const double *g,const int n,int iter);
#endif
