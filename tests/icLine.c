#include "indicurses.h"
#include "test.h"

int main(){
	float t = 0;
	__title("icLine()");

	assert(icInit() == 0);
	icLine(1, 1, 20, 20);

	while(1){
		int hx = IC_TERM_WIDTH >> 1, hy = IC_TERM_HEIGHT >> 1;
		int qx = hx >> 1;

		clear();

		icText(2, 2, "This is some text");
		icCurrentChar = '.';
		//icCircle(hx, hy, 20);

		icCurrentChar = 'o';
		icDial(qx, hy, 10, t + 2);
		icDial(hx, hy, 10, t + 3);
		icDial(hx + qx, hy, 10, t + 6);
		
		t += 0.01f;
		usleep(10000);	
		icPresent();
	} 

	return 0;
}
