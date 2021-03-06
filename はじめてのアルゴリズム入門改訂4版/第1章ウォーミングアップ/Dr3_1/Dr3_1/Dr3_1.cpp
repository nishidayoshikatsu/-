// Dr3_1.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include<stdio.h>

#define Num 10
#define Max 100
#define Min 0

//main関数の定義
int main(void)
{
	//変数と配列の宣言
	int a[Num] = { 56,25,67,88,100,61,55,67,76,56 };
	int i, juni[Max+2];

	//順位計算
	for (i = Min; i <= Max; i++) {
		juni[i] = 0;	//各配列を0で初期化
	}
	for (i = 0; i < Num; i++) {
		juni[a[i]]++;
	}
	juni[Max + 1] = 1;
	for (i = Max; i >=Min; i--) {
		juni[i] = juni[i] + juni[i + 1];
	}

	//画面出力
	printf("　得点　順位\n");
	for (i = 0; i < Num; i++) {
		printf("%6d%6d\n", a[i], juni[a[i] + 1]);
	}

    return 0;
}

