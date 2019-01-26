// Dr2.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

/*
*----------------------------------------
*			 暗号の解読
*----------------------------------------
*/

#include<stdio.h>

//main関数
int main(void)
{
	//変数と配列の宣言
	char table[27] = { 'Q','W','E','R','T','Y','U','I','O',
					'P','A','S','D','F','G','H','J','K',
					'L','Z','X','C','V','B','N','M','?' };
	const char *p="KSOIDHEPZ";
	int index;

	//p = ango;

	while (*p != '\0') {
		if ('A' <= *p && *p <= 'Z') {
			index = *p - 'A';
		}
		else {
			index = 26;
		}
		putchar(table[index]);
		p++;
	}

	printf("\n");

	return 0; //通常終了
}

