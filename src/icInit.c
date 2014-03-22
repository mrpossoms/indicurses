#include "indicurses.h"
#include <ncurses.h>
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int IC_TERM_WIDTH;
int IC_TERM_HEIGHT;
char icCurrentChar = '.';

void __icSigResizeHandler(int signo){
	switch(signo){
		case SIGWINCH:
			getmaxyx(stdscr, IC_TERM_HEIGHT, IC_TERM_WIDTH);
			break;
		case SIGINT:
			endwin();
			exit(0);
	}
}

int icInit(void){
	if(initscr() == NULL) return -1;
	
	clear();

	if(signal(SIGWINCH, __icSigResizeHandler) == SIG_ERR){
		return -2;
	}

	__icSigResizeHandler(SIGWINCH);

	return 0;
}

void icClose(void){
	endwin();
}

void icPresent(void){
	refresh();
}