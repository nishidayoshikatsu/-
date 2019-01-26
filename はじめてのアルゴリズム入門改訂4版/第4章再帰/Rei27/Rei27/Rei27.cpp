// Rei27.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include<stdio.h>

long int kaijo(int n);

int main(void)
{
	int n;

	for (n = 0; n < 13; n++) {
		printf("%2d!=%10ld\n", n, kaijo(n));
	}

    return 0;
}

long int kaijo(int n)
{
	int i;
	long int ans = 1;

	if (n == 0) {
		return 1;
	}
	else {
		for (i = n; i >0; i--) {
			ans = ans * i;
		}
		return ans;
	}
}