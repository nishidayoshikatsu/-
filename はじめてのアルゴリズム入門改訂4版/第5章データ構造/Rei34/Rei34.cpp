#include<stdio.h>
#include<stdlib.h>

struct cell{
	char name[20];
	char tel[20];
	struct cell *next;
};

struct cell *talloc(void);

int main(void)
{
	struct cell *head,*p;
	
	head=NULL;
	//p=(struct cell *)malloc(sizeof(struct cell));
	while(p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF){
		p->next=head;
		head=p;
	}
	
	p=head;
	while(p!=NULL){
		printf("%15s%15s\n",p->name,p->tel);
		p=p->next;
	}
	
	return 0;
}

struct cell *talloc(void)
{
	return (struct cell *)malloc(sizeof(struct cell));
}