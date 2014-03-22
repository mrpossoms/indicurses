#include "indicurses.h"
#include <ncurses.h>
#include <stdlib.h>
#include <math.h>

#define IC_SWAP(i, j){\
	int temp = i;\
	i = j; j = temp;\
}\

void icLine(int x1, int y1, int x2, int y2){
	int steep = abs(y2 - y1) > abs(x2 - x1);
	int dx, dy, err, x, y, yStep;

	if(steep){
		IC_SWAP(x1, y1);
		IC_SWAP(x2, y2);
	}

	if(x1 > x2){
		IC_SWAP(x1, x2);
		IC_SWAP(y1, y2);
	}

	dx = x2 - x1;
	dy = abs(y2 - y1);
	err = dx >> 1;
	y = y1;
	yStep = y1 < y2 ? 1 : -1;

	for(x = x1; x <= x2; x++){
		if(steep)
			mvaddch(x, y, icCurrentChar);
		else
			mvaddch(y, x, icCurrentChar);
		
		err -= dy;
		
		if(err < 0){
			y += yStep;
			err += dx;
		}
	}
}