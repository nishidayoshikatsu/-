// Dr26_4.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include<stdio.h>

int gcd(int m, int n);

int main(void)
{
	int a, b;

	printf("2つの整数を入力してください> ");
	scanf_s("%d %d", &a, &b);

	printf("最大公約数＝%d\n", gcd(a, b));

    return 0;
}

int gcd(int m, int n)
{
	if (m == n) {
		return m;
	}
	else if (m > n) {
		return gcd(m - n, n);
	}
	else {
		return gcd(m, n - m);
	}
}