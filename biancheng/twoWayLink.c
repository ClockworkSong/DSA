/*************************************************************************
	> File Name: twoWayLink.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Sat Jan 18 10:48:40 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
	int data;
	struct Link* prior;
	struct Link* next;
}link_t;

//双向链表的创建
link_t* initLink()
{
	link_t* head = (link_t*)malloc(sizeof(struct Link));
	if(head == NULL) exit(-1);
	head->data = 1;
	head->prior = NULL;
	head->next = NULL;
	link_t* tmp = head;
	for(int i = 2; i <= 5; i ++)
	{
		link_t* q = (link_t*)malloc(sizeof(struct Link));
		if(q == NULL) exit(-1);
		q->data = i;
		q->prior = tmp;
		q->next = NULL;
		tmp->next = q;
		tmp = tmp->next;
	}
	return head;
}
//双向链表的遍历
void display(link_t* p)
{
	link_t* tmp = p;
	while(tmp !=NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
//双链表插入元素,pos表示插入的位置
link_t* insertElem(link_t* p, int pos, int data)
{
	link_t* q = (link_t*)malloc(sizeof(struct Link));
	if(q == NULL) exit(-1);
	q->data = data;
	q->prior = NULL;
	q->next = NULL;
	link_t* tmp = p;
	//插入表头考虑特殊情况
	if(pos == 1)
	{
		tmp->prior = q;
		q->next = tmp;
		return q;
	}
	//找到插入位置的上一个节点
	for(int i = 1 ; i < pos-1; i ++)
	{
		tmp = tmp->next;
	}
	if(tmp->next == NULL)//判断插入是否为尾节点
	{
		tmp->next = q;
		q->prior = tmp;
	}
	else
	{
		tmp->next->prior = q;
		q->next = tmp->next;
		tmp->next = q;
		q->prior = tmp;
	}
	return p;
}
//删除元素
link_t* deleteElem(link_t* p, int elem)
{
	link_t* tmp = p;
	while(tmp)
	{
		if(tmp->data == elem)
		{
			if(tmp->prior == NULL)//判断是否为首节点
			{
				tmp->next->prior =  NULL;
				tmp = tmp->next;
				return tmp;
			}
			else
			{
				if(tmp->next == NULL)
				{
					tmp->prior->next =  NULL;
					return p;
					
				}
				tmp->next->prior = tmp->prior;
				tmp->prior->next = tmp->next;
			}
			free(tmp);
			return p;
		}
		tmp = tmp->next;
	}
	printf("链表中无该元素!\n");
	return p;
}
//修改元素
link_t* amendElem(link_t* p, int pos, int elem)
{
	link_t* tmp = p;
	for(int i = 1; i < pos; i ++)
	{
		tmp = tmp->next;
	}
	tmp->data = elem;
	return p;
}
//查找节点
int selectElem(link_t* p, int elem)
{
	link_t* tmp = p;
	int pos = 0;
	while(tmp)
	{
		pos ++;
		if(tmp->data == elem)
		{
			return pos;
		}
		tmp = tmp->next;
	}
	printf("无此元素!\n");
	return 0;
}

int main()
{
	link_t* t = initLink();
	display(t);
	//插入(3,7)
	t = insertElem(t, 3, 7);
	display(t);
	//插入(1,7)
	t = insertElem(t, 1, 7);
	display(t);
	//插入(8,7)
	t = insertElem(t, 8, 8);
	display(t);
	//删除(1)
	t = deleteElem(t, 1);
	display(t);
	//删除(7)
	t = deleteElem(t, 7);
	display(t);
	//删除(8)
	t = deleteElem(t, 8);
	display(t);
	//修改(1, 255)
	t = amendElem(t, 1, 255);
	display(t);
	//修改(5, 255)
	t = amendElem(t, 5, 255);
	display(t);
	//查找(255)
	int n = selectElem(t, 255);
	printf("pos=%d\n", n);
	//查找(4)
	n = selectElem(t, 4);
	printf("pos=%d\n", n);

	return 0;
}


