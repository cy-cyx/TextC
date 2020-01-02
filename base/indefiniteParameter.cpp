#include <stdarg.h>
#include <iostream>
#include "indefiniteParameter.h"

int indefiniteParamFun(int n,...) {
	va_list vl;
	int sum = 0;
	va_start(vl, n);
	for (int i = 0; i < n; ++i) {
		sum += va_arg(vl, int);
	}
	va_end(vl);
	return sum;
}
