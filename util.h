#include <conio.h> 

#ifndef _COLOR_LIST_
#define _COLOR_LIST_

enum{
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

#endif

void consoleSet();
void gotoxy(int, int);
void setColor(int, int);

