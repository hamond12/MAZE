#include <iostream>  

#ifndef KEY_CODE
#define KEY_CODE

//변수정의 
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3 
#define SUBMIT 4 

#endif

class DrawClass{
	private:
		int x=0;
		int y=0;
	public:
		//게임제목 
		void titleDraw(){
			printf("\n\n\n\n");
			printf("             #       #    #    #####  ##### \n");
			printf("             ##     ##   # #      #   #     \n");
			printf("             # #   # #  #####    #    ##### \n");
			printf("             #  # #  #  #   #   #     #     \n");
			printf("             #   #   #  #   #  #####  ##### \n");
		};
		//게임설명 
		void infoDraw(){
				printf("\n\n\n"); 
				printf("              이동:w,a,s,d  선택:Space bar"); 
		}
};


//함수정의 
void gLoop(); 
void move(int*, int*, int, int, int*); // x,y,_x,_y,playing
int keyControl(); 
int menuDraw();
int mapDraw();
void drawMap(int*, int*);



