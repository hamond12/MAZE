#include "util.h"

// 콘솔창 세팅 
void consoleSet(){
	system("mode con cols=56 lines=20 | title 게임제목"); // 콘솔창 사이즈 조정
	// 콘솔 커서 숨기기 
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible=0; 
	ConsoleCursor.dwSize=1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor); 
}

// 커서 위치 
void gotoxy(int x, int y){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

// 색깔 입히기(글자, 배경) 
void setColor(int text, int background){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = text + background * 16;
	SetConsoleTextAttribute(consoleHandle,code);
}
