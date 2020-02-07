/*************************************************************************
	> File Name: 04link_queue.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Sun Jan 26 10:55:36 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//链表中的节点结构
typedef struct Link
{
	int data;
	struct Link* next;
}link_t;


//创建链式队列函数
link_t* initQueue()
{
	link_t* p = (link_t*)malloc(sizeof(struct Link));
	if(p == NULL) exit(-1);
	p->next = NULL;
	return p;
}

//链式队列数据入列
link_t* enQueue(link_t* p, int elem)
{
	link_t* rear = p;
	link_t* q = (link_t*)malloc(sizeof(struct Link));
	if(q == NULL) exit(-1);
	q->data = elem;
	q->next = NULL;
	rear->next = q;
	rear = rear->next;
	return rear;
}

//链式队列数据出队
link_t* delQueue(link_t* top, link_t* rear)
{
	if(top->next == NULL)
	{
		printf("队列为空!\n");
		return rear;
	}
	link_t* tmp = top->next;
	printf("出队元素:%d \n", tmp->data);
	top->next = tmp->next;
	if(rear == tmp) rear = top;
	free(tmp);
	return rear;
}

int main()
{
	link_t  *top, *rear;
	//创建头结点
	top = rear = initQueue();
	rear = enQueue(rear, 1);
	rear = enQueue(rear, 2);
	rear = enQueue(rear, 3);
	rear = enQueue(rear, 4);
	rear = delQueue(top, rear);
	rear = delQueue(top, rear);
	rear = delQueue(top, rear);
	rear = delQueue(top, rear);
	return 0;
}
