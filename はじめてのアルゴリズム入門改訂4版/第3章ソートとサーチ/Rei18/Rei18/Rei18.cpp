// Rei18.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 50

void print_data(int *a);

int main(void)
{
	int a[N];
	int i, j,imin, temp;
	clock_t start, end;
	double jikan;

	//データの生成
	srand(unsigned int(time(NULL)));
	for (i = 0; i < N; i++) {
		a[i] = rand() % 100;
	}

	printf("ソート前：\n");
	print_data(a);

	start = clock();
	for (i = 0; i < N-1; i++) {
		imin=i;
		for (j = i; j < N; j++) {
			if (a[j] < a[imin]) {
				imin = j;
			}
		}
		temp = a[imin];
		a[imin] = a[i];
		a[i] = temp;
	}
	end = clock();
	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("ソート後：\n");
	print_data(a);
	printf("処理時間＝%.2lf[s]", jikan);

    return 0;
}

void print_data(int *a)
{
	int i;

	for (i = 0; i < N; i++) {
		printf("%d ", *(a + i));
	}
	printf("\n");
}