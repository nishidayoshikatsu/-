#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 6		/* table�ɓo�^����Ă���f�[�^�̌� */

/* Page 12 */

/* List 2.1 ���`�T���@�ɂ��T�� */

struct{
    int key;
    int data;
} table[]={
	{1427,1},
	  {1428,2},
   	  {1417,3},
	  {1402,4},
	  {1401,5},
	  {1434,6},
};

int  search(int key);

int main(void)
{
	  
	int i,ans;
	int searchkey;
	clock_t start,end;
	double jikan;
	
	printf("�����A���`�T���@�����悤����Ȃ����I�I�I\n");
	printf("�ǂ�key��T�΂����񂶂Ⴑ��\n");
	scanf("%d",&searchkey);
	
	start=clock();
	ans=search(searchkey);
	end=clock();
	jikan=(double)(end-start)/CLOCKS_PER_SEC;
	
	if(ans==-1){
		printf("���H�����key�ˁ[������\n");
	}
	else{
		printf("���T����key�̃f�[�^�͂���������H��%d\n",ans);
	}
	printf("�������ԁ�%.2lf[s]\n",jikan);
	
	return 0;
}

int  search(int key)
{
    int i;

    i = 0;
    while (i < N) {
	if (table[i].key == key)
	    return (table[i].data);	/* �������� */
	i++;
    }
    
    return -1;				/* ������Ȃ����� */
}