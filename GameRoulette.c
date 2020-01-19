#include <stdio.h>
#include <stdlib.h>

/*
1.俄罗斯轮盘赌，想必很多人都听说过，一种残忍的赌博游戏。游戏的道具是一把左轮手枪，其规则也很简单：在左轮手枪中的 6 个弹槽中随意放入一颗或者多颗子弹，在任意旋转转轮之后，关上转轮。游戏的参加者轮流把手枪对着自己，扣动扳机：中枪或是怯场，即为输的一方；坚持到最后的即为胜者。
2.本节实践项目同轮盘赌类似，游戏规则：n 个参加者排成一个环，每次由主持向左轮手枪中装一颗子弹，并随机转动关上转轮，游戏从第一个人开始，轮流拿枪；中枪者退出赌桌，退出者的下一个人作为第一人开始下一轮游戏。直至最后剩余一个人，即为胜者。要求：模拟轮盘赌的游戏规则，找到游戏的最终胜者。
*/

typedef struct Link
{
	int num;
	struct Link* next;
}link_t;

//初始化单向循环链表
link_t* initLink(int n)
{
	link_t* p = (link_t*)malloc(sizeof(struct Link));
	if(p == NULL) exit(-1);
	p->num = 1;
	p->next = NULL;
	link_t* tmp = p;
	for(int i = 2; i <= n; i ++)
	{
		link_t* q = (link_t*)malloc(sizeof(struct Link));
		if(q == NULL) exit(-1);
		q->num = i;
		q->next = p;
		tmp->next = q;
		tmp = tmp->next;
	}
	return p;
}	

//链表遍历
void display(link_t* p)
{
	link_t* tmp = p;
	while(tmp->next != p)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("%d \n", tmp->num);
}

int main()
{
	int n = 0;
	printf("请输入参与游戏的人数:");
	scanf("%d", &n);
	link_t* t = initLink(n);
	display(t);
	int round = 1;
	//当且只含有一个节点时退出循环
	while(t->next != t)
	{
		printf("第%d轮开始，从编号为%d的人开始", round, t->num);
		shootNum = rand()%n + 1;
		printf("枪在第%d次扣动扳机会响\n", shootNum);
		link_t* tmp = t;
		//循环遍历找到要删除节点的上一个节点
		for(int i = 1;i < shootNum-1;i ++)
		{
			
			tmp = tmp->next;
		}
	}
	return 0;
}

