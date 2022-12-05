#include <iostream> 
#include <windows.h>

#include "game.h" 
#include "util.h"

//게임시작 누를 때 나오는 맵 
char map[15][57] = { //세로,가로 
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

//맵 출력 
int mapDraw(int* x, int* y){
	system("cls");
	int h,w;
	
	for(h=0;h<14;h++){ //세로 길이까지 
		for(w=0; w<56; w++){ //가로 길이까지 
			char temp = map[h][w];
			if(temp=='0'){ //빈공간 
				setColor(black, black); 
				printf(" ");
			}
			else if(temp=='1'){ //벽 
				setColor(white, white);
				printf("#");
			}
			else if(temp=='s'){ //플레이어 
				//좌표값 저장(gLoop의 x,y변수에 접근) 
				*x=w;
				*y=h;
				setColor(cyan, black);
				printf("@");
			}
			else if(temp='q'){ //목적지 
				setColor(yellow, black);
				printf("O");
			}
		} 
		printf("\n");
	}
	setColor(white,black); //다시 기본 색상으로 
}


//게임실행할때 
void gLoop(){
	int x,y; //플레이어 좌표저장 변수 
	int playing=1; //1이면 게임중, 0이면 게임종료
	mapDraw(&x,&y); //맵 출력 
	
	//플레이 중이면 
	while(playing){
		switch(keyControl()){ //키값에 따라 스위치문 작동 
		case UP:
			move(&x, &y, 0, -1, &playing); //위로 한 칸 
			break; 
		case DOWN:
			move(&x, &y, 0, 1, &playing); //밑으로 한 칸 
			break;
		case RIGHT:
			move(&x, &y, 1, 0, &playing); // 우측으로 한 칸 
			break;
		case LEFT:
			move(&x, &y, -1, 0, &playing); //좌측으로 한 칸 
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

// 플레이어 좌표 조작 함수
// 원래좌표(x,y), 증감할 좌표(_x,_y) 
void move(int* x, int* y, int _x, int _y, int* playing){
	
	//이동할 위치에 있는 문자 임시저장 
	char mapObject = map[*y+_y][*x+_x];
	setColor(white,black); //기본값 색 
	
	//이동할 위치의 오브젝트가 공백이면 
	if(mapObject=='0'){
		
		gotoxy(*x, *y); //현재위치에 있는 거 
		printf(" "); //지우고 
		
		setColor(cyan,black); //색 설정	
		gotoxy(*x+_x, *y+_y); //증감한 위치로 이동 후 
		printf("@"); //플레이어출력 
		
		//좌표값 업데이트
		*x += _x;
		*y += _y; 
	}
	else if(mapObject=='q'){
		*playing=0;
	}
	
	//벽은 아무런 동작을 하지않아서 설정 필요x 
}

int menuDraw(){
	int x=24;
	int y=15;
	gotoxy(x-2, y);
	printf("> 게임시작");
	gotoxy(x,y+1);
	printf("게임종료");
	while(1){
		int n = keyControl();
		switch(n){
			case UP:{ //w누르면 
				if(y>15){ //y는 15,16까지이동 
					gotoxy(x-2,y); //">"출력하려고 x-2 
					printf(" "); //원래 위치 지우고 
					gotoxy(x-2,--y); //이동한 위치로 
					printf(">"); //다시그리기 
				}
				break;
			} 
			case DOWN:{ //s누르면 
				if(y<16){ //y값의 최대는 16 
					gotoxy(x-2,y);
					printf(" ");
					gotoxy(x-2,++y);
					printf(">");
				}
				break; 
			}
			
			case SUBMIT:{ //스페이스바누르면 
				return y-15; //키값 반환 
			}
		}
	}
} 
