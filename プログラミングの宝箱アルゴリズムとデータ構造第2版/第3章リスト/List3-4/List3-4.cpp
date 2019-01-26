#include<stdio.h>
#include<stdlib.h>

typedef struct tagListNode{
	struct tagListNode *prev;
	struct tagListNode *next;
	int data;
}ListNode;

int main(void)
{
	int buf,sum;
	ListNode *firstnode,*lastnode,*newnode,*thisnode,*removenode;
	
	firstnode= NULL;
	lastnode = NULL;
	
	do{
		printf("整数を入力してください(0を入力すると終了): ");
		scanf("%d",&buf);
		if(buf){
			newnode=(ListNode *)malloc(sizeof(ListNode));
			newnode->data=buf;
			newnode->next=NULL;
			
			if(lastnode!=NULL){		//最後のノードに新しいノードを接続
				lastnode->next=newnode;
				newnode->prev=lastnode;
				lastnode=newnode;
			}
			else{				//これが最初の要素の場合
				firstnode=newnode;
				lastnode=newnode;
				newnode->prev=NULL;
			}
		}
	}while(buf!=0);
	
	printf("入力されたのは以下の数です。\n");
	sum=0;
	for(thisnode=firstnode;thisnode!=NULL;thisnode=thisnode->next){
		printf("%d\t",thisnode->data);
		sum+=thisnode->data;
	}
	
	printf("\n");
	printf("以上の数の合計値は%dです。\n",sum);
	
	for(thisnode=firstnode;thisnode!=NULL;thisnode=thisnode->next){
		removenode=thisnode;
		free(removenode);
	}
	
	return 0;
}