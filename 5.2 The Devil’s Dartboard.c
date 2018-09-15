#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#define SIZE 20 

int main(void)
{
	char s[22];
	int total=0;
	int i;
	
	s[20]=s[0];
	s[21]=s[1];
	
	for(i=0;i<SIZE;i++){
		total = total+(pow(s[i]+s[i+1]+s[i+2], 2));
		printf("total %d. = (%d+%d+%d)^2 = %d\n", i+1, s[i], s[i+1], s[i+2], total);
		getchar();
	}	
	
	system("pause");
	return 0;
} 
