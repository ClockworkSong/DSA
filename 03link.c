#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
	int data;//代表数据域
	struct Link* next;//代表指针域，指向直接后继元素
}link_t;//link为节点名，每个节点都是一个link结构体

//链表初始化
#if 0
//创建一个存储节点且无头节点的链表
link_t* initLink()
{
	link_t* head = NULL;//创建头指针
	link_t* p = (link_t*)malloc(sizeof(struct Link));//创建首元节点
	if(p == NULL) 
	{
		printf("Memory malloc error!\n");
		exit(-1);
	}
	//首元节点初始化
	p->data = 1;
	p->next = NULL;
	head = p;//头指针指向首元节点
	//从第二个节点开始创建
	for(int i = 2; i < 5; i++)
	{
		link_t* q = (link_t*)malloc(sizeof(struct Link));
		if(q == NULL) 
		{
			printf("Memory malloc error!\n");
			exit(-1);
		}
		q->data = i;
		q->next = NULL;
		p->next = q;//将p与新建立的节点q建立逻辑关系
		p = p->next;//p节点每次都指向新链表的最后一个节点
	}
	return head;//返回头指针tmp
}
#else	
//创建一个存储且包含头结点的链表
link_t* initLink()
{
	link_t* p = (link_t*)malloc(sizeof(struct Link));//创建一个头节点
	if(p == NULL) 
	{
		printf("Memory malloc error!\n");
		exit(-1);
	}
	link_t* tmp = p;//声明一个指针指向头结点
	//从第一个首元节点开始创建
	for(int i = 1; i < 5; i++)
	{
		link_t* q = (link_t*)malloc(sizeof(struct Link));
		if(q == NULL) 
		{
			printf("Memory malloc error!\n");
			exit(-1);
		}
		q->data = i;
		q->next = NULL;
		tmp->next = q;//将p与新建立的节点q建立逻辑关系
		tmp = tmp->next;//p节点每次都指向新链表的最后一个节点
	}
	return p;
}
#endif

//链表插入元素
/*
1.将新节点的next指针指向插入位置后的节点
2.将插入位置前节点的next指针指向插入节点
*/
void insertElem(link_t* p, int pos, int elem)
{
	link_t* tmp = p;
	//找到要插入位置的上一个节点
	for(int i = 1; i < pos; i++)
	{	
		if(tmp == NULL)
		{
			printf("插入位置无效\n");
			exit(-1);
		}
		tmp = tmp->next;
	}
	//创建新节点
	link_t* q = (link_t*)malloc(sizeof(struct Link));
	if(q == NULL) exit(-1);
	q->data = elem;
	//向链表中插入新节点
	q->next = tmp ->next;
	tmp->next = q;
}

//链表删除元素
/*
1.将节点从链表中摘下
2.手动释放节点，回收被节点占用的存储空间
*/
void deleteElem(link_t* p, int pos)
{
	link_t* tmp = p;
	//找到要删除位置的上一个节点
	for(int i = 1; i < pos; i++)
	{	
		if(tmp == NULL)
		{
			printf("删除位置无效\n");
			exit(-1);
		}
		tmp = tmp->next;
	}
	link_t* q = tmp->next;//单独设置一个指针指向被删除的节点
	tmp->next = tmp->next->next;//更改前一个节点的指针域
	free(q);//释放该节点，防止内存泄漏
}

//链表修改元素
void amendElem(link_t* p, int pos, int elem)
{
	link_t* tmp = p;
	//找到要修改位置的上一个节点
	for(int i = 1; i < pos; i++)
	{	
		if(tmp == NULL)
		{
			printf("修改位置无效\n");
			exit(-1);
		}
		tmp = tmp->next;
	}
	tmp->next->data = elem;
}

//链表的遍历
void display(link_t* p)
{
	link_t* tmp = p;
	while(tmp->next)
	{
		tmp = tmp->next;
		printf("%d ", tmp->data);
	}
	printf("\n");
}

int main()
{
	link_t* t = initLink();
	display(t);
	insertElem(t, 5, 5);
	insertElem(t, 3, 255);
	insertElem(t, 1, 25);
	display(t);
	deleteElem(t, 1);
	deleteElem(t, 6);
	deleteElem(t, 2);
	display(t);
	amendElem(t, 1, 99);
	amendElem(t, 4, 99);
	amendElem(t, 2, 99);
	display(t);

	return 0;
}

