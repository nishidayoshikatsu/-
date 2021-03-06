// Dr1_2.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

/*
*----------------------------------------
*			Pascalの三角形
*----------------------------------------
*/

#include<stdio.h>
#define N 12

//プロトタイプ宣言
long combi(int, int);

//main関数
int main(void)
{
	//変数宣言
	int n, r, t;

	for (n = 0; n <= N; n++){
		for (t = 0; t < (N - n) * 3; t++) {
			printf(" ");	//空白
		}
		for (r = 0; r <= n; r++) {
			printf("%3ld   ", combi(n, r));
		}
		printf("\n");
	}

    return 0;
}

//combi関数
long combi(int n, int r)
{
	//変数宣言
	int i;
	long p = 1;

	for (i = 1; i <= r; i++) {
		p = p * (n - i + 1) / i;
	}

	return p;
}