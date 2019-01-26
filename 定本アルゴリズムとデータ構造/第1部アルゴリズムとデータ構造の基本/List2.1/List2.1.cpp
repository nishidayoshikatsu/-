#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 6		/* tableに登録されているデータの個数 */

/* Page 12 */

/* List 2.1 線形探索法による探索 */

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
	
	printf("さあ、線形探索法をしようじゃないか！！！\n");
	printf("どのkeyを探ばいいんじゃこら\n");
	scanf("%d",&searchkey);
	
	start=clock();
	ans=search(searchkey);
	end=clock();
	jikan=(double)(end-start)/CLOCKS_PER_SEC;
	
	if(ans==-1){
		printf("あ？そんなkeyねーぞこら\n");
	}
	else{
		printf("お探しのkeyのデータはこれっすか？→%d\n",ans);
	}
	printf("処理時間＝%.2lf[s]\n",jikan);
	
	return 0;
}

int  search(int key)
{
    int i;

    i = 0;
    while (i < N) {
	if (table[i].key == key)
	    return (table[i].data);	/* 見つかった */
	i++;
    }
    
    return -1;				/* 見つからなかった */
}