#include "indicurses.h"
#include <stdlib.h>
#include <math.h>

void icPoint(int x, int y){
	mvaddch(y, x, icCurrentChar);
}
