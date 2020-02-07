#include <stdio.h>

#define MAX 100

//入队
int enQueue(int* a, int rear, int elem)
{
	a[rear++] = elem;
	return rear;
}

//单个出队
int delQueue(int* a, int front, int rear)
{
	//如果front==rear表示队列为空
	if(front == rear)
	{
		printf("队列为空\n");
		return front;
	}
	printf("出列元素为:%d\n", a[front++]);
	
	return front;
}
//全部出列
void allDelQueue(int* a, int front, int rear)
{
	//如果front==rear表示队列为空
	while(front != rear)
	{
		printf("出列元素为:%d\n", a[front++]);
	}
}

int main()
{
	int arr[MAX];
	int front, rear;
	front = rear = 0;//设置头指针和队尾指针,当队列中没有元素时,队头和队尾指向同一块地址
	rear = enQueue(arr, rear, 1);
	rear = enQueue(arr, rear, 2);
	rear = enQueue(arr, rear, 3);
	rear = enQueue(arr, rear, 4);
	rear = enQueue(arr, rear, 5);
	front = delQueue(arr, front, rear);
	front = delQueue(arr, front, rear);
	allDelQueue(arr, front, rear);

	return 0;
}
