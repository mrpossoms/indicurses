#include "indicurses.h"
#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
