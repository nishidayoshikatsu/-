// Dr26_1.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include<stdio.h>

long int fib(long int n);


int main(void)
{
	long int i;

	for (i = 1; i <= 20; i++) {
		printf("%3ld: %ld\n", i, fib(i));
	}

    return 0;
}

long int fib(long int n)
{
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		return (fib(n - 1) + fib(n - 2));
	}
}