#ifndef __INDICURSES
#define __INDICURSES

#ifdef __cplusplus
extern "C" {
#endif

#include <ncurses.h>

extern int IC_TERM_WIDTH;
extern int IC_TERM_HEIGHT;
extern char icCurrentChar;

int  icInit(void);
void icClose(void);
void icPresent(void);
void icPoint(int x, int y);
void icLine(int x1, int y1, int x2, int y2);
void icCircle(int x, int y, int radius);
void icDial(int x, int y, int radius, float theta);
void icBarGraph(int minX, int minY, int maxX, int maxY, int percent);
void icLineGraph(int topLeftCoord[2], int bottomRightCoord[2], char lineChar, int* data, unsigned int dataPoints, int* minMax);
void icText(int x, int y, const char* msg);
void icTextf(int x, int y, const char* format, ...);


#ifdef __cplusplus
}
#endif

#endif
