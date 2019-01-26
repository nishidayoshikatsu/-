#include<stdio.h>
#include<stdlib.h>

#define M 7
#define N 7

int count[M+1];

void print_data(int *a);
void dist_count_sort(int a[],int b[],int n);

int main(void)
{
	int a[N];
	int b[N];
	int i;
	
	srand((unsigned int)time(NULL));
	for(i=0;i<N;i++){
		a[i]=rand()%(M+1);
	}
	
	printf("ソート前：\n");
	print_data(a);
	
	dist_count_sort(a,b,N);
	
	printf("ソート後：\n");
	print_data(b);
	
	return 0;
}

void print_data(int *a)
{
	int i;
	
	for(i=0;i<N;i++){
		printf("%d\t",*(a+i));
	}
	printf("\n");
}

void dist_count_sort(int a[],int b[],int n)
{
	int i;
	
	for(i=0;i<=M;i++){
		count[i]=0;
	}
	
	for(i=0;i<n;i++){
		count[a[i]]++;
	}
	
	for(i=0;i<M;i++){
		count[i+1]+=count[i];
	}
	
	/*for(i=0;i<=M;i++){
		printf("%d\t",count[i]);
	}*/
	
	for(i=n-1;i>=0;i--){
		b[--count[a[i]]]=a[i];
	}
}