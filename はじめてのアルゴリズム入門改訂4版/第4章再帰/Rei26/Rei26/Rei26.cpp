// Rei26.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include<stdio.h>

long int kaijo(int n);

int main(void)
{
	int i;

	for (i = 0; i < 13; i++) {
		printf("%2d!=%10ld\n", i, kaijo(i));
	}

    return 0;
}

long int kaijo(int n)
{
	if (n == 0) {
		return (1);
	}
	else {
		return (n * kaijo(n - 1) );
	}
}