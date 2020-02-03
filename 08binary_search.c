/*************************************************************************
	> File Name: 08binary_search.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Mon Feb  3 20:43:46 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int key;//查找表中每个数据元素的值
}node_t;

typedef struct Table
{
	node_t* ele;//存放查找表中数据元素的数组
	int len;
}tab_t;

tab_t* initTable(int len, const int* arr)
{
	tab_t* t = (tab_t*)malloc(sizeof(struct Table));
	if(t == NULL) exit(-1);
	t->len = len;
	t->ele = (node_t*)malloc(len*sizeof(struct Node));
	if(t->ele == NULL) exit(-1);
	for(int i = 0; i < len; i++)
	{
		t->ele[i].key = arr[i];
	}
	return t;
}

void display(tab_t* t)
{
	for(int i = 0; i < t->len; i++)
	{
		printf("%d ",t->ele[i].key);
	}
	printf("\n");
}
//折半查找算法
void findKey(tab_t* t, int key)
{
	int hasKey = 0;
	int low = 1;//low指针指向第一个关键字
	int high = t->len;//high指向最后一个关键字
	int mid = 0;
	while(low<=high)
	{
		mid = (low+high)/2;//指向中心位置,每次为取整的整数
		if(t->ele[mid].key == key)
		{
			hasKey = 1;
			break;
		}
		else if(t->ele[mid].key > key)//mid指向的关键字较大，跟新high
		{
			high = mid - 1;
		}
		else//反之跟新low
		{
			low = mid + 1;
		}
	}
	if(hasKey == 1)
	{
		printf("数据在查表中的位置:%d\n", mid);
	}
	else
	{
		printf("查找失败!\n");
	}
}

int main()
{
	const int arr[11] = {5,13,19,21,37,56,64,75,80,88,92};
	tab_t* t = initTable(11, arr);
	display(t);
	printf("请输入查找元素的关键字:");
	int key = 0;
	scanf("%d", &key);
	findKey(t, key);

	return 0;
}

