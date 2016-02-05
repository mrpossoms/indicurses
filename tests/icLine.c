#include "indicurses.h"
#include "test.h"
#include <stdio.h>
#include <ncurses.h>

int main(){
	float t = 0;
	__title("icLine()");

	assert(icInit() == 0);
	icLine(1, 1, 20, 20);

	while(1){
		int hx = IC_TERM_WIDTH >> 1, hy = IC_TERM_HEIGHT >> 1;
		int qx = hx >> 1, qy = hy >> 1;
		char buf[32];

		clear();

		sprintf(buf, "t = %f", t);
		icText(2, 2, buf);
		icCurrentChar = '.';

		icCurrentChar = 'o';
		icDial(qx, qy, 10, t + 2);
		icDial(hx, qy, 10, t + 3);
		icDial(hx + qx, qy, 10, t + 6);

		int topLeft[2] = { 5, qy + 10 };
		int bottomRight[2] = { IC_TERM_WIDTH - 5, IC_TERM_HEIGHT - 2};
		int data[100];

		for(int i = 100; i--;){
			data[i] = (10 + sin(10 * (t + i * 0.01)) * 100 * sin(t + i * 0.01));
		}

		icLineGraph(topLeft, bottomRight, '*', data, 100);

		t += 0.01f;

		if(t > M_PI){
			t = -M_PI;
		}

		usleep(10000);
		icPresent();
	}

	return 0;
}
