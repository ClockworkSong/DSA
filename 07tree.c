/*************************************************************************
	> File Name: 07tree.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Sat Feb  1 15:48:32 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
	int data;
	struct Tree* lchild;//左孩子指针
	struct Tree* rchild;//右孩子指针
}tree_t;

tree_t* createTree()
{
	//根节点
	tree_t* t = (tree_t*)malloc(sizeof(struct Tree));
	if(t == NULL) exit(-1);
	t->data = 1;
	//第二层
	t->lchild = (tree_t*)malloc(sizeof(struct Tree));
	if(t == NULL) exit(-1);
	t->lchild->data = 2;
	t->rchild = (tree_t*)malloc(sizeof(struct Tree));
	if(t == NULL) exit(-1);
	t->rchild->data = 3;
	//第三层
	t->lchild->lchild = (tree_t*)malloc(sizeof(struct Tree));
	if(t == NULL) exit(-1);
	t->lchild->lchild->data = 4;
	t->lchild->rchild = NULL;
	t->rchild->lchild = NULL;
	t->rchild->rchild = NULL;
	//第四层
	t->lchild->lchild->lchild = NULL;
	t->lchild->lchild->rchild = NULL;
	return t;
}

void display(tree_t* t)
{
	printf("%d\n", t->lchild->lchild->data);
}

int main()
{
	tree_t* t = createTree();
	display(t);

	return 0;
}

