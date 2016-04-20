#include "indicurses.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#define IC_SWAP(i, j){\
	int temp = i;\
	i = j; j = temp;\
}\

void icText(int x, int y, const char* msg){
	int i, len = strlen(msg);

	for(i = 0; i < len; i++){
		mvaddch(y, x+i, msg[i]);
	}
}

void icTextf(int x, int y, const char* format, ...)
{
	char buf[1024] = {};
	va_list args;

	va_start(args, format);
	vsnprintf(buf, (size_t)sizeof(buf), format, args);
	va_end(args);

	icText(x, y, buf);
}
