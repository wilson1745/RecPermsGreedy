#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define SIZE 5

int maze[SIZE][SIZE]={{2,2,2,2,2},
					  {2,0,0,0,2},
					  {2,0,0,0,2},
					  {2,0,0,0,2},
					  {2,2,2,2,2}};
					  
int startI=1, startJ=1;

int main(void)
{
	int i, j;
	
	printf("Εγ¥ά°Ο¶τ: \n");
	
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(maze[i][j]==2){
				printf("Άi");
			}
			if(maze[i][j]==0){
				printf(" ");
			}
		}
	}
	
	system("pause");
	return 0;
} 



