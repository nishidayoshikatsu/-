#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int buf,sum,count,n,i,count2=0;
	int *array;
	
	printf("何個の数値を入力しますか: ");
	scanf("%d",&count);
	
	array=(int *)malloc(sizeof(int)*count);
	
	n=0;
	do{
		printf("整数を入力してください(0を入力すると終了): ");
		scanf("%d",&buf);
		if(buf!=0){
			array[n]=buf;
			n++;
			count2++;
		}
		if(count2==count){
			break; 
		}
	}while(buf!=0);
	
	printf("入力されたのは以下の数です\n");
	sum=0;
	for(i=0;i<n;i++){
		printf("%d\t",array[i]);
		sum+=array[i];
	}
	printf("\n");
	printf("以上の数の合計は%dです\n",sum);
	
	free(array);
	
	return 0;
}