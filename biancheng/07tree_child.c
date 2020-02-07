/*************************************************************************
	> File Name: 07tree_child.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Sun Feb  2 12:19:26 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct Node
{
	int child;//存储数据在数组中存储位置下标
	struct Node* next;
}node_t;

typedef struct Box
{
	char data;
	node_t* fchild;//孩子链表头指针
}box_t;

typedef struct Tree
{
	box_t arr[SIZE];//存储节点数组
	int num;//节点数量
	int root;//树根位置
}tree_t;

tree_t initTree()
{
	tree_t t;
	t.num = 7;
	/*printf("输入节点数量:");
	scanf("%d", &(t.num));
	for(int i = 0; i < (t.num); i++)
	{
		printf("输入第%d个节点的值:\n", i+1);
		fflush(stdin);
		scanf("%c", &(t.arr[i].data));
		t.arr[i].fchild = (node_t*)malloc(sizeof(struct Node));
		if(t.arr[i].fchild == NULL) exit(-1);
		t.arr[i].fchild->next = NULL;
		printf("输入节点%c的孩子节点数量:\n", t.arr[i].data);
		int cn = 0;
		scanf("%d", &cn);
		if(cn != 0)
		{
			printf("cn=%d\n", cn);
		}
	}*/
	t.arr[0].data = 'R';
	t.arr[0].fchild = (node_t*)malloc(sizeof(struct Node));
	if(t.arr[0].fchild == NULL) exit(-1);
	t.arr[0].fchild->next = NULL;
	node_t* p = t.arr[0].fchild;
	for(int i = 0; i < 3; i ++)
	{
		node_t* q = (node_t*)malloc(sizeof(struct Node));
		if(q == NULL) exit(-1);
		q->next = NULL;
		q->child = i+1;
		p->next = q;
		p = p->next;
	}
	
	t.arr[1].data = 'A';
	t.arr[1].fchild = (node_t*)malloc(sizeof(struct Node));
	if(t.arr[1].fchild == NULL) exit(-1);
	t.arr[1].fchild->next = NULL;
	p = t.arr[1].fchild;
	for(int i = 0; i < 2; i ++)
	{
		node_t* q = (node_t*)malloc(sizeof(struct Node));
		if(q == NULL) exit(-1);
		q->next = NULL;
		q->child = i+4;
		p->next = q;
		p = p->next;
	}
	
	t.arr[2].data = 'B';
	t.arr[2].fchild = (node_t*)malloc(sizeof(struct Node));
	if(t.arr[2].fchild == NULL) exit(-1);
	t.arr[2].fchild->next = NULL;

	t.arr[3].data = 'C';
	t.arr[3].fchild = (node_t*)malloc(sizeof(struct Node));
	if(t.arr[3].fchild == NULL) exit(-1);
	t.arr[3].fchild->next = NULL;
	p = t.arr[3].fchild;
	node_t* q = (node_t*)malloc(sizeof(struct Node));
	if(q == NULL) exit(-1);
	q->next = NULL;
	q->child = 6;
	p->next = q;
	p = p->next;

	t.arr[4].data = 'D';
	t.arr[4].fchild = (node_t*)malloc(sizeof(struct Node));
	if(t.arr[4].fchild == NULL) exit(-1);
	t.arr[4].fchild->next = NULL;
	
	t.arr[5].data = 'E';
	t.arr[5].fchild = (node_t*)malloc(sizeof(struct Node));
	if(t.arr[5].fchild == NULL) exit(-1);
	t.arr[5].fchild->next = NULL;
	
	t.arr[6].data = 'F';
	t.arr[6].fchild = (node_t*)malloc(sizeof(struct Node));
	if(t.arr[6].fchild == NULL) exit(-1);
	t.arr[6].fchild->next = NULL;
	
	return t;
}

void findKids(tree_t t, char ch)
{
	int hasKid = 0;
	for(int i = 0; i < t.num; i++)
	{
		if(t.arr[i].data == ch)
		{
			node_t* p = t.arr[i].fchild->next;
			while(p)
			{
				hasKid = 1;
				printf("%c ", t.arr[p->child].data);
				p = p->next;
			}
			printf("\n");
			break;
		}
	}
	if(hasKid == 0) printf("查无此节点\n");
}

int main()
{
	tree_t t = initTree();
	t.root = 0;
	printf("找出节点F的所有孩子节点:");
	findKids(t, 'R');
	return 0;
}

