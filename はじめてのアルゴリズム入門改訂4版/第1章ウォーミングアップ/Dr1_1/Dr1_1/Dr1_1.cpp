// Dr1_1.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

/*
*----------------------------------------
*			Hornerの方法
*----------------------------------------
*/

#include<stdio.h>

//プロトタイプ宣言
double fn(double, double*, int);

//main関数
int main(void)
{
	//配列、変数宣言
	double a[] = { 1,2,3,4,5 };	//係数
	double x;

	for (x = 1; x <= 5; x++) {
		printf("fn(%f)=%f\n", x, fn(x, a, 4));
	}

	return 0;
}

//fn関数
double fn(double x, double a[], int n)
{
	//変数宣言
	double p;
	int i;

	p = a[n];

	for (i = n - 1; i >= 0; i--) {
		p = p * x + a[i];
	}

	//pをmain関数に戻す
	return p;
}

