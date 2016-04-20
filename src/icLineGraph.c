#include "indicurses.h"
#include <stdlib.h>
#include <math.h>

static int _min(int* data, unsigned int points)
{
	int min = data[0];

	for(;points--;){
		min = data[points] < min ? data[points] : min;
	}

	return min;
}

static int _max(int* data, unsigned int points)
{
	int max = data[0];

	for(;points--;){
		max = data[points] > max ? data[points] : max;
	}

	return max;
}

static int _map(int x, int in_min, int in_max, int out_min, int out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void icLineGraph(int topLeftCoord[2], int bottomRightCoord[2], char lineChar, int* data, unsigned int dataPoints, int* minMax)
{
	int w  = bottomRightCoord[0] - topLeftCoord[0];
	int h  = bottomRightCoord[1] - topLeftCoord[1];
	int hh = h >> 1;
	int origin[2] = { topLeftCoord[0], bottomRightCoord[1] };
	char lastChar = icCurrentChar;

	int min = minMax[0];
	int max = minMax[1];

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
					origin[0] + i, _map(data[(int)(i * di)], min, max, bottomRightCoord[1], topLeftCoord[1]),
					origin[0] + (i - 1), _map(data[(int)((i - 1) * di)], min, max, bottomRightCoord[1], topLeftCoord[1])
				);
			}
		}
	}

	char buf[32] = {};
	sprintf(buf, "%d", max);
	icText(topLeftCoord[0] + 1, topLeftCoord[1], buf);

	sprintf(buf, "%d", min);
	icText(topLeftCoord[0] + 1, bottomRightCoord[1], buf);

	icCurrentChar = lastChar;
}
