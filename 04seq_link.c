#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	int data;
	struct Queue* next;
}queue_t;


//创建链式队列的函数
queue_t* initQueue()
{
	//创建头结点
	queue_t* t = (queue_t*)malloc(sizeof(struct Queue));
	if(t == NULL) exit(-1);
	t->next = NULL;
	return t;
}

//入列
queue_t* enQueue(queue_t* rear, int elem)
{
	queue_t* tmp = rear;
	//节点包裹入列
	queue_t* q = (queue_t*)malloc(sizeof(struct Queue));
	if(q == NULL) exit(-1);
	q->data = elem;
	q->next = NULL;
	//新节点与rear节点建立联系
	tmp->next = q;
	//tmp指向新节点
	tmp = q;
	printf("入列元素:%d\n", q->data);
	return tmp;
}
//出列
queue_t* delQueue(queue_t* top, queue_t* rear)
{
	if(top->next == NULL)
	{
		printf("队列为空\n");
		return rear;
	}
	queue_t* tmp = top->next;
	printf("出列元素:%d\n", tmp->data);
	top->next = tmp->next;
	if(rear == tmp)
	{
		rear = top;
	}
	free(tmp);
	return rear;
}

int main()
{
	queue_t* top;
	queue_t* rear;
	queue_t* q;
	q=top=rear=initQueue();//创建头结点
	//向链队列中添加结点，使用尾插法添加的同时，队尾指针需要指向链表的最后一个元素
	rear=enQueue(rear, 1);
	rear=enQueue(rear, 2);
	rear=enQueue(rear, 3);
	rear=enQueue(rear, 4);
	//入队完成，所有数据元素开始出队列
	rear=delQueue(top, rear);
	rear=delQueue(top, rear);
	rear=delQueue(top, rear);
	rear=delQueue(top, rear);
	rear=delQueue(top, rear);
	return 0;
}

