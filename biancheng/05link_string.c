/*************************************************************************
	> File Name: 05link_string.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Wed Jan 29 20:40:19 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4//设置链表中节点存储个数

typedef struct Link
{
	char a[SIZE];//数据域可存放SIZE个数据
	struct Link* next;
}link_t;

//初始化链表,head为头指针,str为存储字符串
link_t* initLink(link_t* head, const char* str)
{
	//创建并初始化首元节点
	head = (link_t*)malloc(sizeof(struct Link));
	if(head == NULL) exit(-1);
	head->next = NULL;
	link_t* tmp = head;
	//根据字符串长度计算出链表中使用节点的个数
	int Length = strlen(str);
	int Number = Length / SIZE;
	if(Length%SIZE) Number++;//非整数则扩充一个节点
	printf("所需节点个数Number=%d\n", Number);
	//初始化链表
	for(int i = 0; i < Number; i++)
	{
		int j = 0;
		for(; j < SIZE; j++)
		{
			if(i*SIZE + j < Length)
			{
				tmp->a[j] = str[i*SIZE + j]; 
			}
			else
			{
				tmp->a[j] = '#';
			}
		}
		if(i*SIZE + j < Length)
		{
			link_t* q = (link_t*)malloc(sizeof(struct Link));
			if(q == NULL) exit(-1);
			q->next = NULL;
			tmp->next = q;
			tmp = tmp->next;
		}
	}
	return head;
}

//遍历
void display(link_t* p)
{
	link_t* tmp = p;
	while(tmp)
	{
		for(int i = 0; i < SIZE; i ++)
			printf("%c", tmp->a[i]);
		tmp = tmp->next;
	}
	printf("\n");
}

int main()
{
	link_t* t = NULL;
	t = initLink(t, "data.biancheng.net");
	display(t);
	return 0;
}

