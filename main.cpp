#include <iostream> 
#include <windows.h>
#include <conio.h> 

#include "game.h"
#include "util.h"

//메인함수 
int main() {
	consoleSet();
	while(1){
		DrawClass draw;
		draw.titleDraw();
		draw.infoDraw();
		int menuCode = menuDraw();
		if(menuCode==0){
			gLoop();
		} 
		else if(menuCode==1){
			return 0; //종료 
		}
		system("cls"); //콘솔창 모든 글자 비우기, 콘솔좌표 0,0으로 초기화 
		setColor(white,black); //색 기본값으로 설정 
	} 
	
	return 0;	 
}
