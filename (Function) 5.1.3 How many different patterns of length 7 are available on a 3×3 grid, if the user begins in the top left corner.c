#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define SIZE 5
#define LAST 9 

void visit(int ,int );
void Mapprint(); 

int startI=2, startJ=2;
int maze[SIZE][SIZE]={{2,2,2,2,2},
					  {2,0,0,0,2},
					  {2,0,0,0,2},
					  {2,0,0,0,2},
					  {2,2,2,2,2}};
int k=1, p=1;
int tmp[SIZE][SIZE];
int times=1;
					  
int main(void)
{
	int i, j;
	
	printf("顯示區塊: \n");	
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(maze[i][j]==2){
				printf("X");
			}
			if(maze[i][j]==0){
				printf(" ");
			}
		}
		printf("\n");
	}
	getchar();
	visit(startI, startJ);
	
	system("pause");
	return 0;
} 

void visit(int x, int y)
{
	maze[x][y]=1;
	tmp[x][y]=p;
	
	Mapprint();	
	if(maze[x][y+1]==0){			// 往右
		k++;
		if(p<LAST){
			p++;	
		}
		else if(p>=LAST){
			p=k;
		}
		visit(x,y+1);
	}
	if(maze[x+1][y]==0){			// 往下 
		k++;
		if(p<LAST){
			p++;	
		}
		else if(p>=LAST){
			p=k;
		}		
		visit(x+1,y);
	}
	if(maze[x][y-1]==0){				// 往左
		k++;
		if(p<LAST){
			p++;
		}
		else if(p>=LAST){
			p=k;
		}
		visit(x,y-1);
	}
	if(maze[x-1][y]==0){		 		// 往上
		k++;
		if(p<LAST){
			p++;	
		}
		else if(p>=LAST){
			p=k;
		}
		visit(x-1,y);
	}
	k--;
	maze[x][y]=0;
}

void Mapprint()
{
	int m,n;

	if(k==LAST){
		printf("\n顯示路徑: %d\n", times);
			times++;
		for(m=0;m<SIZE;m++){
			for(n=0;n<SIZE;n++){
				if (maze[m][n] == 2) {
					printf("X");
				}
				else if (maze[m][n] == 1) {			// 路徑 
					printf("%d", tmp[m][n]);
				}
			}
			printf("\n");
		}
		getchar();	
	}
}


