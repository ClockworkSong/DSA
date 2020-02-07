/*************************************************************************
	> File Name: 08lookup_seq.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Mon Feb  3 16:39:39 2020
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
	int len;//记录查找表中数据的总数量
}tab_t;

tab_t* initTable(int len)
{
	tab_t* t = (tab_t*)malloc(sizeof(struct Table));
	if(t == NULL) exit(-1);
	t->len = len;
	t->ele = (node_t*)malloc(len*sizeof(struct Node));
	if(t->ele == NULL) exit(-1);
	//printf("输入表中的数据元素:\n");
	for(int i = 0; i < len; i++)
	{
		t->ele[i].key = i+1;
	}
	return t;
}

void display(tab_t* t)
{
	for(int i = 0; i < 6; i++)
	{
		printf("%d ",t->ele[i].key);
	}
	printf("\n");
}

void findKey(tab_t* t, int key)
{
	int hasKey = 0;
	int i = 0;
	for(i = 0; i < t->len; i++)
	{
		if(t->ele[i].key == key)
		{
			hasKey = 1;
			break;
		}
	}
	if(hasKey == 1)
	{
		printf("数据在查表中的位置:%d\n", i);
	}
	else
	{
		printf("查找失败!\n");
	}
}

int main()
{
	tab_t* t = initTable(6);
	display(t);
	printf("请输入查找元素的关键字:");
	int key = 0;
	scanf("%d", &key);
	findKey(t, key);

	return 0;
}

