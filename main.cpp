#include <iostream> 
#include <windows.h>
#include <conio.h> 

#include "game.h"
#include "util.h"

//�����Լ� 
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
			return 0; //���� 
		}
		system("cls"); //�ܼ�â ��� ���� ����, �ܼ���ǥ 0,0���� �ʱ�ȭ 
		setColor(white,black); //�� �⺻������ ���� 
	} 
	
	return 0;	 
}
