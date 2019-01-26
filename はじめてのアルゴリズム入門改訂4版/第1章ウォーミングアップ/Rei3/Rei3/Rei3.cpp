// Rei3.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include<stdio.h>

#define Num 10

//main関数の定義
int main(void)
{
	//変数と配列の宣言
	int i, j;
	int juni[Num];
	int a[Num] = { 56,25,67,88,100,61,55,67,76,56 };

	//順位計算
	for (i = 0; i < Num; i++) {
		juni[i] = 1;
		for (j = 0; j < Num; j++) {
			if (a[i] < a[j]) {
				juni[i]++;
			}
		}
	}

	//画面出力
	printf("　得点　順位\n");
	for (i = 0; i < Num; i++) {
		printf("%6d%6d\n", a[i], juni[i]);
	}

    return 0;
}