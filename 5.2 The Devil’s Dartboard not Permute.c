#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#define SIZE 22			// 印出x個字母 x-2個不同字母 
#define SCOPE 20 		// 計算次數 

int Min=20100;
int list[SIZE];
int i, j;

int main(void)
{
	int times = 0;
	srand(time(NULL));
	
	do{
		for(i=0;i<SCOPE;i++){
			do{											
				list[i]=rand()%SCOPE+1;				/* 第一個list[0]一定部會和list[j]衝突，因為i=j */			
				for(j=0;j<i;j++){
					if(list[i] == list[j]){		    /* 第一個list[i=0]會依序儲存到list[j=0]的陣列(重要)這樣就可以去比對 https://www.youtube.com/watch?v=yUdLjNeoKLc*/
						break;
					}
				}
			}while(j!=i);
		}	
	
		list[SIZE-2]=list[0];
		list[SIZE-1]=list[1];
		
		int total=0;
	
		for(i=0;i<SCOPE;i++){
			total=total+(pow(list[i]+list[i+1]+list[i+2], 2));
		}
		if(total == Min){
			times--;
			continue;
		}
		if(total<Min){
			Min = total;
			printf("Total = %d : ", total);
			for(i=0;i<SIZE;i++){
				printf("%2d ", list[i]);	
			}
			printf("\n");	
		}
		times++;
	}while(times!=5000000);

	
	system("pause");
	return 0;
} 




