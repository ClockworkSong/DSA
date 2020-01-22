#include <stdio.h>

#define MAX 5

//入队
int enQueue(int* a, int front, int rear, int elem)
{
	//如果rear+1和front重合,则表示数组已满
	if((rear+1)%MAX == front)
	{
		printf("入队数据%d失败，空间已满!\n", elem);
		return rear;
	}
	//如果rear超过MAX,则直接将其从a[0]重新开始存储
	a[rear%MAX] = elem;
	rear ++;
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
	printf("出列元素为:%d\n", a[front]);
	//front不再直接+1,而是+1后同max进行比较,如果=max,则直接跳转到a[0]
	front = (front+1)%MAX;
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
	//入队
	rear = enQueue(arr, front, rear, 1);
	rear = enQueue(arr, front, rear, 2);
	rear = enQueue(arr, front, rear, 3);
	rear = enQueue(arr, front, rear, 4);
	rear = enQueue(arr, front, rear, 255);
	rear = enQueue(arr, front, rear, 254);

	//出队
	front = delQueue(arr, front, rear);
	rear = enQueue(arr, front, rear, 5);
	front = delQueue(arr, front, rear);
	rear = enQueue(arr, front, rear, 6);
	front = delQueue(arr, front, rear);
	front = delQueue(arr, front, rear);
	front = delQueue(arr, front, rear);
	front = delQueue(arr, front, rear);

	return 0;
}

