#include "indicurses.h"
#include <stdlib.h>
#include <math.h>


void icDial(int x, int y, int radius, float theta){
	char last = icCurrentChar;

	icCurrentChar = '.';
	icCircle(x, y, radius);

	icCurrentChar = last;
	icLine(
		x, y,
		x + (int)(cos(theta) * radius),
		y + (int)(sin(theta) * (radius >> 1))
	);	
}
