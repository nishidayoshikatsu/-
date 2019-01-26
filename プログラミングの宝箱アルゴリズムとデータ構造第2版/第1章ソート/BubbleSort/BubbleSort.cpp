#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10

void BubbleSort(int sort[]);
void print_data(int sort[]);

int main(void)
{
	int i;
	int sort[N];
	
	srand((unsigned int)time(NULL));
	for(i=0;i<N;i++){
		sort[i]=rand()%100;
	}
	printf("ソート前\n");
	print_data(sort);
	
	BubbleSort(sort);
	
	printf("ソート後\n");
	print_data(sort);
	
	return 0;
}

void BubbleSort(int sort[])
{
	int i,j,flag;
	
	do{
		flag=0;
		for(i=0;i<N-1;i++){
			if(sort[i]>sort[i+1]){
				flag=1;
				j=sort[i];
				sort[i]=sort[i+1];
				sort[i+1]=j;
			}
		}
	}while(flag==1);
}

void print_data(int sort[])
{
	int i;
	
	for(i=0;i<N;i++){
		printf("%d\t",sort[i]);
	}
	printf("\n");
}