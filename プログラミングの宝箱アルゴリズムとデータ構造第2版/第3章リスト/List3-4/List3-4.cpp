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
		printf("��������͂��Ă�������(0����͂���ƏI��): ");
		scanf("%d",&buf);
		if(buf){
			newnode=(ListNode *)malloc(sizeof(ListNode));
			newnode->data=buf;
			newnode->next=NULL;
			
			if(lastnode!=NULL){		//�Ō�̃m�[�h�ɐV�����m�[�h��ڑ�
				lastnode->next=newnode;
				newnode->prev=lastnode;
				lastnode=newnode;
			}
			else{				//���ꂪ�ŏ��̗v�f�̏ꍇ
				firstnode=newnode;
				lastnode=newnode;
				newnode->prev=NULL;
			}
		}
	}while(buf!=0);
	
	printf("���͂��ꂽ�͈̂ȉ��̐��ł��B\n");
	sum=0;
	for(thisnode=firstnode;thisnode!=NULL;thisnode=thisnode->next){
		printf("%d\t",thisnode->data);
		sum+=thisnode->data;
	}
	
	printf("\n");
	printf("�ȏ�̐��̍��v�l��%d�ł��B\n",sum);
	
	for(thisnode=firstnode;thisnode!=NULL;thisnode=thisnode->next){
		removenode=thisnode;
		free(removenode);
	}
	
	return 0;
}