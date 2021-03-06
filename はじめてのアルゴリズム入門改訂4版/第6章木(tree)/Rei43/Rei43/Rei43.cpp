// Rei43.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
	struct node *left;
	struct node *right;
	char name[12];
};


int main(void)
{
	char data[12];
	struct node *root, *p, *prev;

	root = (struct node *)malloc(sizeof(struct node));
	printf("木の根ノードの構成> ");
	scanf_s("%s", root->name);
	root->right = NULL;
	root->left = NULL;

	while (scanf_s("%s", data) != EOF) {
		p = root;
		while (p != NULL) {
			prev = p;
			if (strcmp(data, p->name) <= 0) {
				p = p->left;
			}
			else {
				p = p->right;
			}
		}
		p = (struct node *)malloc(sizeof(struct node));
		strcpy_s(p->name, data);
		p->left = NULL;
		p->right = NULL;
		if (strcmp(data, prev->name) <= 0) {
			prev = prev->left;
		}
		else {
			prev = prev->right;
		}
	}

    return 0;
}