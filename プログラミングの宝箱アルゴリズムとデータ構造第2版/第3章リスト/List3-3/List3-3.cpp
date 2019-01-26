#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int main(void)
{
	int buf,sum,count,n,size;
	int *array,*temp;
	
	size=10;
	array=(int *)malloc(sizeof(int)*size);
	
	count=0;
	do{
		printf("整数を入力してください(0を入力すると終了): ");
		scanf("%d",&buf);
		if(buf!=0){
			array[count]=buf;
			count++;
			if(count==size){
				temp=(int *)malloc(sizeof(int)*size*2);
				memcpy(temp,array,sizeof(int)*size);
				free(array);
				array=temp;
				size*=2;
			}
		}
	}while(buf!=0);
	
	printf("入力されたのは以下の数です。\n");
	sum=0;
	for(n=0;n<count;n++){
		printf("%d\t",array[n]);
		sum+=array[n];
	}
	printf("\n");
	printf("以上の数の合計値は%dです。\n",sum);
	
	free(array);
	return 0;
}