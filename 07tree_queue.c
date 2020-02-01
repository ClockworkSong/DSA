/*************************************************************************
	> File Name: 07tree_queue.c
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
int g_rear = 0;//队头指针
int g_front = 0;//队尾指针
//入队函数
void enQueue(tree_t* a, tree_t* t)
{
	a[g_rear++] = *t;
}
//出队函数
tree_t delQueue(tree_t* a)
{
	return a[g_front++];
}

int main()
{
	tree_t* t = createTree();
	printf("层次遍历:\n");

	tree_t q;
	//采用顺序队列，初始化创建队列数组
	tree_t a[20];
	//根节点入队
	enQueue(a, t);
	//当队头和队尾相等时，表示队列为空
	while(g_front < g_rear)
	{
		//队头节点出队
		q = delQueue(a);
		printf("%d ", q.data);
		//将队头和队尾相等时，表示队列为空
		if(q.lchild != NULL) enQueue(a, q.lchild);
		if(q.rchild != NULL) enQueue(a, q.rchild);
	}
	printf("\n");
	
	return 0;
}

