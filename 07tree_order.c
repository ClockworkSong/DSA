/*************************************************************************
	> File Name: 07tree_order.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Sat Feb  1 15:48:32 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	t->lchild->rchild = (tree_t*)malloc(sizeof(struct Tree));
	if(t == NULL) exit(-1);
	t->lchild->rchild->data = 5;
	t->rchild->lchild = (tree_t*)malloc(sizeof(struct Tree));
	if(t == NULL) exit(-1);
	t->rchild->lchild->data = 6;
	t->rchild->rchild = (tree_t*)malloc(sizeof(struct Tree));
	if(t == NULL) exit(-1);
	t->rchild->rchild->data = 7;
	//第四层
	t->lchild->lchild->lchild = NULL;
	t->lchild->lchild->rchild = NULL;
	t->lchild->rchild->lchild = NULL;
	t->lchild->rchild->rchild = NULL;
	t->rchild->lchild->lchild = NULL;
	t->rchild->lchild->rchild = NULL;
	t->rchild->rchild->lchild = NULL;
	t->rchild->rchild->rchild = NULL;
	return t;
}

void preOrderDisplay(tree_t* t)
{
	if(t != NULL)
	{
		printf("%d\n", t->data);
		preOrderDisplay(t->lchild);
		preOrderDisplay(t->rchild);
	}
	//如果节点为空则返回上层
	return;
}

void inOrderDisplay(tree_t* t)
{
	if(t != NULL)
	{
		inOrderDisplay(t->lchild);
		printf("%d\n", t->data);
		inOrderDisplay(t->rchild);
	}
	//如果节点为空则返回上层
	return;
}

void postOrderDisplay(tree_t* t)
{
	if(t != NULL)
	{
		postOrderDisplay(t->lchild);
		postOrderDisplay(t->rchild);
		printf("%d\n", t->data);
	}
	//如果节点为空则返回上层
	return;
}

int main()
{
	tree_t* t = createTree();
	printf("先序遍历:\n");
	preOrderDisplay(t);
	printf("中序遍历:\n");
	inOrderDisplay(t);
	printf("后序遍历:\n");
	postOrderDisplay(t);
	
	return 0;
}

