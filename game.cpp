#include <iostream> 
#include <windows.h>

#include "game.h" 
#include "util.h"

//���ӽ��� ���� �� ������ �� 
char map[15][57] = { //����,���� 
	{"11111111111111111111111111111111111111111111111111111111"}, 
	{"10000010001000110001000000000010001000001000100000110001"},
	{"10110010101010111101011111011010101011101010101010001001"},
	{"10001010100010000001010001011010101011101010001111111001"},
	{"11101000101111111101010101011110001000101011111000000001"},
	{"10001111111000000001010101000000011101101010001010111101"},
	{"10111000001011111111010101110111000000100010100010100001"},
	{"10001011111010000000010100000001110110101000101000100001"},
	{"11101010000010101001010110111100000000101010101010001101"},
	{"10001010111010111001000000000111111110101010101011111101"},
	{"10111010110010001001111011110001000010101010100010000001"},
	{"10s010101111111110110010100001011110100010111110100q0001"},
	{"10001000000000000010001000111100000010101000000010000001"},
	{"11111111111111111111111111111111111111111111111111111111"}
};

//�� ��� 
int mapDraw(int* x, int* y){
	system("cls");
	int h,w;
	
	for(h=0;h<14;h++){ //���� ���̱��� 
		for(w=0; w<56; w++){ //���� ���̱��� 
			char temp = map[h][w];
			if(temp=='0'){ //����� 
				setColor(black, black); 
				printf(" ");
			}
			else if(temp=='1'){ //�� 
				setColor(white, white);
				printf("#");
			}
			else if(temp=='s'){ //�÷��̾� 
				//��ǥ�� ����(gLoop�� x,y������ ����) 
				*x=w;
				*y=h;
				setColor(cyan, black);
				printf("@");
			}
			else if(temp='q'){ //������ 
				setColor(yellow, black);
				printf("O");
			}
		} 
		printf("\n");
	}
	setColor(white,black); //�ٽ� �⺻ �������� 
}


//���ӽ����Ҷ� 
void gLoop(){
	int x,y; //�÷��̾� ��ǥ���� ���� 
	int playing=1; //1�̸� ������, 0�̸� ��������
	mapDraw(&x,&y); //�� ��� 
	
	//�÷��� ���̸� 
	while(playing){
		switch(keyControl()){ //Ű���� ���� ����ġ�� �۵� 
		case UP:
			move(&x, &y, 0, -1, &playing); //���� �� ĭ 
			break; 
		case DOWN:
			move(&x, &y, 0, 1, &playing); //������ �� ĭ 
			break;
		case RIGHT:
			move(&x, &y, 1, 0, &playing); // �������� �� ĭ 
			break;
		case LEFT:
			move(&x, &y, -1, 0, &playing); //�������� �� ĭ 
			break;	
		}
	}
	gotoxy(26,7);
	printf("Clear!");
	Sleep(1500);	
}


int keyControl(){
	char temp = _getch();
	
	if(temp=='w'||temp=='W'){
		return UP;
	}
	else if(temp=='s'||temp=='S'){
		return DOWN;
	}
	else if(temp=='d'||temp=='D'){
		return RIGHT;
	}
	else if(temp=='a'||temp=='A'){
		return LEFT;
	}
	else if(temp==' '){
		return SUBMIT;
	}
}

// �÷��̾� ��ǥ ���� �Լ�
// ������ǥ(x,y), ������ ��ǥ(_x,_y) 
void move(int* x, int* y, int _x, int _y, int* playing){
	
	//�̵��� ��ġ�� �ִ� ���� �ӽ����� 
	char mapObject = map[*y+_y][*x+_x];
	setColor(white,black); //�⺻�� �� 
	
	//�̵��� ��ġ�� ������Ʈ�� �����̸� 
	if(mapObject=='0'){
		
		gotoxy(*x, *y); //������ġ�� �ִ� �� 
		printf(" "); //����� 
		
		setColor(cyan,black); //�� ����	
		gotoxy(*x+_x, *y+_y); //������ ��ġ�� �̵� �� 
		printf("@"); //�÷��̾���� 
		
		//��ǥ�� ������Ʈ
		*x += _x;
		*y += _y; 
	}
	else if(mapObject=='q'){
		*playing=0;
	}
	
	//���� �ƹ��� ������ �����ʾƼ� ���� �ʿ�x 
}

int menuDraw(){
	int x=24;
	int y=15;
	gotoxy(x-2, y);
	printf("> ���ӽ���");
	gotoxy(x,y+1);
	printf("��������");
	while(1){
		int n = keyControl();
		switch(n){
			case UP:{ //w������ 
				if(y>15){ //y�� 15,16�����̵� 
					gotoxy(x-2,y); //">"����Ϸ��� x-2 
					printf(" "); //���� ��ġ ����� 
					gotoxy(x-2,--y); //�̵��� ��ġ�� 
					printf(">"); //�ٽñ׸��� 
				}
				break;
			} 
			case DOWN:{ //s������ 
				if(y<16){ //y���� �ִ�� 16 
					gotoxy(x-2,y);
					printf(" ");
					gotoxy(x-2,++y);
					printf(">");
				}
				break; 
			}
			
			case SUBMIT:{ //�����̽��ٴ����� 
				return y-15; //Ű�� ��ȯ 
			}
		}
	}
} 
