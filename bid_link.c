/*************************************************************************
	> File Name: bid_link.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Fri Jan 17 23:10:14 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Line
{
	int data;
	struct Line* prior;
	struct Line* next;
}line_t;

line_t* initLine()
{
	line_t* tmp = (line_t*)malloc(sizeof(struct Line));
	if(tmp == NULL) exit(-1);
	tmp->data = 1;
	tmp->prior = NULL;
	tmp->next = NULL;
	line_t* head = tmp;
	for(int i = 2; i < 5; i ++)
	{
		line_t* q = (line_t*)malloc(sizeof(struct Line));
		if(q == NULL) exit(-1);
		q->data = i;
		q->prior = tmp;
		q->next = NULL;
		tmp->next = q;
		tmp = tmp->next;
	}
	return head;
}

void display(line_t* p)
{	
	line_t* tmp = p;
	/*
	while(tmp->next != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}*/
	while(tmp)
	{
		if(tmp->next == NULL) printf("%d\n", tmp->data);
		else printf("%d <-> ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

int main()
{
	line_t* t = initLine();
	display(t);
}

