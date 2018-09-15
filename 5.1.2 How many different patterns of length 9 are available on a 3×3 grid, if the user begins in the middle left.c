#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define SIZE 5
#define LAST 9 

void visit(int ,int );

int startI=2, startJ=1;
int maze[SIZE][SIZE]={{2,2,2,2,2},
					  {2,0,0,0,2},
					  {2,0,0,0,2},
					  {2,0,0,0,2},
					  {2,2,2,2,2}};
int k=1;
int p=1;
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
	
	visit(startI, startJ);
	
	system("pause");
	return 0;
} 

void visit(int x, int y)
{
	int m,n;
	
	maze[x][y]=1;
	tmp[x][y]=p;
	
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
	}
	// 往右
	if(maze[x][y+1]==0){
		k++;
		if(p<LAST){
			p++;	
		}
		else if(p>=LAST){
			p=k;
		}
		visit(x,y+1);
	}
	// 往下 
	if(maze[x+1][y]==0){
		k++;
		if(p<LAST){
			p++;	
		}
		else if(p>=LAST){
			p=k;
		}		
		visit(x+1,y);
	}
	// 往左
	if(maze[x][y-1]==0){
		k++;
		if(p<LAST){
			p++;
		}
		else if(p>=LAST){
			p=k;
		}
		visit(x,y-1);
	}
	// 往上
	if(maze[x-1][y]==0){		 
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


