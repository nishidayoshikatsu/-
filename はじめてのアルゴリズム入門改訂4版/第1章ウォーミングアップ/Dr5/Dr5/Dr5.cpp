// Dr5.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include<stdio.h>
#include<stdlib.h>

#define Num 10000

//main関数の定義
int main(void)
{
	int i, in = 0;
	double x, y, S;

	//データの生成
	for (i = 0; i < Num; i++) {
		x = 2 * (double)rand() / RAND_MAX;
		y = (double)rand() / RAND_MAX;
		if (((x*x) / 4 + y * y) <= 1) {
			in++;
		}
	}
	S = 4*(double)2 * in / Num;
	printf("面積は%lfですよお。\n", S);

    return 0;
}

