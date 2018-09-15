#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRINGLENGTH 5  // includes null terminators
#define STRINGLENGTHFILE 6 // includes newline char & null termainators
#define SEQUENCELENGTH 4
#define TOTALWORDS 5

void permute(int *sequence, int l, int r, char *word1, char *word2, int *sucess);
void swap(int *a, int *b);
void printsequence(int *sequence);
void printladder(char wordladder[][STRINGLENGTH]);
int changeletters(char *word1, char *word2, int *editsequence);
int isword(char *array);

int main(int argc, char *argv[])
{
	int sequence[]={1,2,3,4};
	int success=0;
	
	if(argc<3){
		fprintf(stderr, "%s\n", "Usage:hs17931 word1 word2");
		exit(1);
	}
	permute(sequence, 0, SEQUENCELENGTH-1, argv[1], argv[2], & success);
	if(success==0){
		printf("No solution found\n");
	}
	
	system("pause");
	return 0;
} 

void permute(int *sequence, int l, int r, char *word1, char *word2, int *success)
{
	int i;
	
	if(l==r){
		if(changeletters(word1, word2, sequence)!=0){
			printf("Solution found: \n");
			printsequence(sequence);
			printf("\n");
			*success=1;
		}
		return ;
	}
	for(i=l;i<=r;i++){
		swap(&sequence[l], &sequence[i]);
		permute(sequence, l+1, r, word1, word2, success);
		swap(&sequence[l], &sequence[i]);
	}
}

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void printsequence(int *sequence)
{
	int i;
	
	for(i=0;i<STRINGLENGTH; i++){
		printf("%d", sequence[i]);
	}
	printf("\n");
}

void printladder(char wordladder[][STRINGLENGTH])
{
	int rows, cols;
	
	for(rows=0;rows<TOTALWORDS; rows++){
		for(cols=0;cols<STRINGLENGTH;cols++){
			printf("%c", wordladder[rows][cols]);
		}
	}
}

int changeletters(char *word1, char *word2, int *editsequence)
{
	int i, j;
	char temp1[sizeof(word1)];
	char temp2[sizeof(word2)];
	char wordladder[TOTALWORDS][STRINGLENGTH];
	
	strcpy(temp1, word1);
	strcpy(temp2, word2);
	for(i=0;i<SEQUENCELENGTH; i++){
		strcpy(wordladder[i], temp1);
		j=editsequence[i]-1;
		temp1[j]=temp2[j];
		if(isword(temp1)==0){
			return 0;
		}
	}
	strcpy(wordladder[i], temp1); // *add final word to ladder
	printladder(wordladder);
	return 1;
}

int isword(char *array)
{
	char wordstring[STRINGLENGTHFILE];
	FILE *fp;
	fp=fopen("C:\\Users\\Wei-Shen Lo\\Google ¶³ºÝµwºÐ\\1. Computer Science\\C»y¨¥\\§@·~\\Week 5 RecPermsGreedy\\34words.txt", "r");
	if(fp==NULL){
		fprintf(stderr, "%s\n", "Error opening wordlist file");
		exit(1);
	}	
	while(fgets(wordstring, STRINGLENGTHFILE, fp)!=NULL){
		if(wordstring[strlen(wordstring)-1]=='\n'){
			wordstring[strlen(wordstring)-1]='\0';
		} // ^strips out newline characters^ 
		if(strcmp(array, wordstring)==0){
			return 1;
		}
	}
	system("pause");
	return 0;
}
