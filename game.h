#include <iostream>  

#ifndef KEY_CODE
#define KEY_CODE

//�������� 
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
		//�������� 
		void titleDraw(){
			printf("\n\n\n\n");
			printf("             #       #    #    #####  ##### \n");
			printf("             ##     ##   # #      #   #     \n");
			printf("             # #   # #  #####    #    ##### \n");
			printf("             #  # #  #  #   #   #     #     \n");
			printf("             #   #   #  #   #  #####  ##### \n");
		};
		//���Ӽ��� 
		void infoDraw(){
				printf("\n\n\n"); 
				printf("              �̵�:w,a,s,d  ����:Space bar"); 
		}
};


//�Լ����� 
void gLoop(); 
void move(int*, int*, int, int, int*); // x,y,_x,_y,playing
int keyControl(); 
int menuDraw();
int mapDraw();
void drawMap(int*, int*);



