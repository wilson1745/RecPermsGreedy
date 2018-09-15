#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#define CAPS 64
#define SIZE 22			// 印出x個字母 x-2個不同字母 
#define SCOPE 20 		// 計算次數 

void permute(char a[], int l, int n); 
void SWAP(char *A, char *B);

int Min=1;
char Minarray[SIZE];

int main(void)
{
	char str[]="ABCDEFGHIJKLMNOPQRST";
	int n = strlen(str);
	int j;
	
	printf("\n");
	permute(str, 0, n-1);
	
	printf("Min = %d  :", Min);
	for(j=0;j<SIZE;j++){
		printf("  %d", Minarray[j]);
	}
	printf("\n\n");

	
	system("pause");
	return 0;
} 

void permute(char a[], int l, int r)
{
	int i;
	char tmp[SIZE];
	char s1[SIZE];
	
	if(l==r){
		for(i=0;i<SCOPE;i++){
			tmp[i]=(a[i]-CAPS);
			s1[i]=a[i];
		}
		tmp[SIZE-2]=tmp[0];
		tmp[SIZE-1]=tmp[1];
		s1[SIZE-2]=s1[0];
		s1[SIZE-1]=s1[1];
						
		int total=0;

		for(i=0;i<SCOPE;i++){
			total = total+(pow(tmp[i]+tmp[i+1]+tmp[i+2], 2));
		}
		
		if(total<Min){
			Min=total;
			for(i=0;i<SIZE;i++){
				Minarray[i]=tmp[i]; 
			}
	
		}
					printf("total = %d  :  %s  :", total, s1);
			for(i=0;i<SIZE;i++){
				printf("%3d", tmp[i]);
			}
			printf("\n");

				
		return;
	}
	for(i=l;i<=r;i++){
		SWAP(&a[l], &a[i]);
		permute(a,l+1,r);
		SWAP(&a[l], &a[i]);
	}
}

void SWAP(char *A, char *B)
{
	char tmp; 
	
	tmp=*A; 		// tmp對應指標A裡位址的值 
	*A=*B; 
	*B=tmp;
}
