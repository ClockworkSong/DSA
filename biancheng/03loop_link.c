#include <stdio.h>
#include <stdlib.h>

/*
循环链表实现约瑟夫环
约瑟夫环问题，是一个经典的循环链表问题，题意是：已知 n 个人（分别用编号 1，2，3，…，n 表示）围坐在一张圆桌周围，从编号为 k 的人开始顺时针报数，数到 m 的那个人出列；他的下一个人又从 1 开始，还是顺时针开始报数，数到 m 的那个人又出列；依次重复下去，直到圆桌上剩余一个人。
*/
typedef struct Node
{
	int num;
	struct Node* next;
}node_t;

//循环链表初始化
node_t* initNode(int n)
#if 0
{
	node_t* head = (node_t*)malloc(sizeof(struct Node));
	if(head == NULL) exit(-1);
	head->num = 1;
	head->next = NULL;
	node_t* tmp = head;
	for(int i = 2; i <= n; i ++)
	{
		node_t* q = (node_t*)malloc(sizeof(struct Node));
		if(q == NULL) exit(-1);
		q->num = i;
		q->next = NULL;
		tmp->next = q;
		tmp = tmp->next;
	}
	tmp->next = head;
	return head;
}
#else
{
	node_t* head = NULL;
	node_t* p = (node_t*)malloc(sizeof(struct Node));
	if(p == NULL) exit(-1);
	p->num = 1;
	p->next = NULL;
	head = p;
	for(int i = 2; i <= n; i ++)
	{
		node_t* q = (node_t*)malloc(sizeof(struct Node));
		if(q == NULL) exit(-1);
		q->num = i;
		q->next = NULL;
		p->next = q;
		p = p->next;
	}
	p->next = head;//首尾相连
	return head;
}
#endif

void findAndKill(node_t* p, int k, int m)
{
	//找到链表第一个节点的上一个节点，为删除做准备
	node_t* tail = p;
	while(tail->next != p)
	{
		tail = tail->next;
	}
	//找到编号为k的节点
	node_t* q = p;
	while(q->num != k)
	{	
		tail = q;
		q = q->next;
	}
	//从编号为k的节点开始，只要符合q->next==q时，说明链表中除了p节点，所有编号都出列了
	while(q->next != q)
	{
		//找到从q报数1开始,报m的节点，并且要知道m-1的节点位置tail，方便删除
		for(int i = 1; i < m; i++)
		{	
			tail = q;
			q = q->next;
		}
		tail->next = q->next;//从链表上将q节点摘除
		printf("%d出列\n", q->num);
		free(q);
		q = tail->next;
	}
	printf("%d胜出!\n", q->num);
}

int main()
{
	int n = 0;
	int k = 0;
	int m = 0;
	printf("请输入圆桌上的人数:");
	scanf("%d", &n);
	printf("从第k人开始报数(k>1且k<%d):", n);
	node_t *p = initNode(n);
	scanf("%d", &k);
	printf("数到m的人出列:");
	scanf("%d", &m);
	findAndKill(p, k, m);

	return 0;
}
