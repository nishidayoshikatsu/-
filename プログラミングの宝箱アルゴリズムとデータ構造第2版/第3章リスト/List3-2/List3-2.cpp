#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int buf,sum,count,n,i,count2=0;
	int *array;
	
	printf("���̐��l����͂��܂���: ");
	scanf("%d",&count);
	
	array=(int *)malloc(sizeof(int)*count);
	
	n=0;
	do{
		printf("��������͂��Ă�������(0����͂���ƏI��): ");
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
	
	printf("���͂��ꂽ�͈̂ȉ��̐��ł�\n");
	sum=0;
	for(i=0;i<n;i++){
		printf("%d\t",array[i]);
		sum+=array[i];
	}
	printf("\n");
	printf("�ȏ�̐��̍��v��%d�ł�\n",sum);
	
	free(array);
	
	return 0;
}