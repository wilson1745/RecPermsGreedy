#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#define SIZE 22			// �L�Xx�Ӧr�� x-2�Ӥ��P�r�� 
#define SCOPE 20 		// �p�⦸�� 

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
				list[i]=rand()%SCOPE+1;				/* �Ĥ@��list[0]�@�w���|�Mlist[j]�Ĭ�A�]��i=j */			
				for(j=0;j<i;j++){
					if(list[i] == list[j]){		    /* �Ĥ@��list[i=0]�|�̧��x�s��list[j=0]���}�C(���n)�o�˴N�i�H�h��� https://www.youtube.com/watch?v=yUdLjNeoKLc*/
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




