#include "indicurses.h"
#include <ncurses.h>
#include <stdlib.h>
#include <math.h>

void icCircle(int x, int y, int r){
	int i = (int)(r * M_PI) - 1;
	int hr = r >> 1;
	int lx = x + r, ly = y;
	float segs = i;

	for(;i--;){
		int i2 = i << 1;
		int nx = (int)(cos(i2 * M_PI / segs) * r) + x;
		int ny = (int)(sin(i2 * M_PI / segs) * hr) + y;
		icLine(
			lx, ly,
			nx, ny
		);
		lx = nx; ly = ny;
	}
}