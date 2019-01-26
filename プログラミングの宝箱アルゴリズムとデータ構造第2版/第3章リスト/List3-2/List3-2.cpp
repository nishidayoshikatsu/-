#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int buf,sum,count,n,i,count2=0;
	int *array;
	
	printf("‰½ŒÂ‚Ì”’l‚ğ“ü—Í‚µ‚Ü‚·‚©: ");
	scanf("%d",&count);
	
	array=(int *)malloc(sizeof(int)*count);
	
	n=0;
	do{
		printf("®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢(0‚ğ“ü—Í‚·‚é‚ÆI—¹): ");
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
	
	printf("“ü—Í‚³‚ê‚½‚Ì‚ÍˆÈ‰º‚Ì”‚Å‚·\n");
	sum=0;
	for(i=0;i<n;i++){
		printf("%d\t",array[i]);
		sum+=array[i];
	}
	printf("\n");
	printf("ˆÈã‚Ì”‚Ì‡Œv‚Í%d‚Å‚·\n",sum);
	
	free(array);
	
	return 0;
}