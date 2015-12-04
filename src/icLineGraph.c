#include "indicurses.h"
#include <ncurses.h>
#include <stdlib.h>
#include <math.h>

void icLineGraph(int topLeftCoord[2], int bottomRightCoord[2], char lineChar, int* data, unsigned int dataPoints)
{
	int w = bottomRightCoord[0] - topLeftCoord[0];
	int h = bottomRightCoord[1] - topLeftCoord[1];
	int origin[2] = { topLeftCoord[0], bottomRightCoord[1] };
	char lastChar = icCurrentChar;

	// draw y axis
	icCurrentChar = '|';
	icLine(topLeftCoord[0], topLeftCoord[1], topLeftCoord[0], bottomRightCoord[1] - 1);

	// draw x axis
	icCurrentChar = '-';
	icLine(topLeftCoord[0] + 1, bottomRightCoord[1], bottomRightCoord[0], bottomRightCoord[1]);

	// draw the joint at the graph corner
	icCurrentChar = '+';
	icLine(topLeftCoord[0], bottomRightCoord[1], topLeftCoord[0], bottomRightCoord[1]);

	// render the data
	icCurrentChar = lineChar;

	if(dataPoints){
		float di = dataPoints / (float)w;
		for(int i = w; i--;){
			if(i){
				icLine(
					origin[0] + i, origin[1] - data[(int)(i * di)],
					origin[0] + (i - 1), origin[1] - data[(int)((i - 1) * di)]
				);
			}
		}
	}

	icCurrentChar = lastChar;
}