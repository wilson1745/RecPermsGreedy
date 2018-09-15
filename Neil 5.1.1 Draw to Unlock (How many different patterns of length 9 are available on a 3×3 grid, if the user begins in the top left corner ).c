#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <malloc.h>
#include <assert.h>
#define SIZE 3
#define BLANK ' '

void possPath(char a[SIZE][SIZE], int x, int y, int len);
int valid(char a[SIZE][SIZE], int x, int y);
void print(char a[SIZE][SIZE]);

int main(void)
{
	char sc[SIZE][SIZE];		// Clear Array
	memset(sc, BLANK, SIZE*SIZE);
	
	possPath(sc, 0, 0, 9);

	system("pause");
	return 0;
} 

void possPath(char a[SIZE][SIZE], int x, int y, int len)
{
	static int c=0;
	
	if(len==1){
		printf("進到len==1\n");
		a[y][x]='*';
		print(a);
		printf("%d\n\n", ++c);
		a[y][x]=BLANK;
		return ;
	}
	
	if(valid(a, x-1, y)!=0){
		printf("進入valid(a, x-1, y)!=0\n");
		a[y][x]='<';
		possPath(a, x-1, y, len-1);
		a[y][x]=BLANK;
	}
	
	if(valid(a, x+1, y)!=0){
		printf("進入valid(a, x+1, y)!=0\n");

		a[y][x]='>';
		possPath(a, x+1, y, len-1);
		a[y][x]=BLANK;
	}
	
	if(valid(a, x, y-1)!=0){
		printf("進入valid(a, x, y-1)!=0\n");
		
		a[y][x]='^';
		possPath(a, x, y-1, len-1);
		a[y][x]=BLANK;
	}
	
	if(valid(a, x, y+1)!=0){
		printf("進入valid(a, x, y+1)!=0\n");

		a[y][x]='V';
		possPath(a, x, y+1, len-1);
		a[y][x]=BLANK;
	}		
}

int valid(char a[SIZE][SIZE], int x, int y)
{
	if((x<0) || (y<0) || (x>=SIZE) || (y>=SIZE)){		// 超出邊界即算行走失敗 
		return 0;
	}
	if(a[y][x]!=BLANK){				//  
		return 0;
	}
	return 1;
}

void print(char a[SIZE][SIZE])
{
	int i, j;
	char bar[SIZE*2+2];
	
	memset(bar, '-', SIZE*2+1);
	bar[SIZE*2+2]='\0';
	for(j=0;j<SIZE;j++){
		printf("%s\n", bar);
		for(i=0;i<SIZE;i++){
			printf("|%c", a[j][i]);
		}
		printf("|\n");
	}
	printf("%s\n", bar);
}
