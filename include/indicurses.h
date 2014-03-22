#ifndef __INDICURSES
#define __INDICURSES

extern int IC_TERM_WIDTH;
extern int IC_TERM_HEIGHT;
extern char icCurrentChar;

int  icInit(void);
void icClose(void);
void icPresent(void);
void icLine(int x1, int y1, int x2, int y2);
void icCircle(int x, int y, int radius);
void icDial(int x, int y, int radius, float theta);
void icBarGraph(int minX, int minY, int maxX, int maxY, int percent);

#endif