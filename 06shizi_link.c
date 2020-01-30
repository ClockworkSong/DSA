/*************************************************************************
	> File Name: 06shizi_link.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Fri Jan 31 16:44:18 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
	int i, j, k;//行标列标元素值
	struct Link* right;//右指针，代表列数
	struct Link* down;//下指针，代表行数
}link_t, *Link_t;

typedef struct CrossList
{
	int i, j, k;//矩阵的行数、列数和非零元的个数
	Link_t* rhead;//行链表头指针
	Link_t* chead;//列链表头指针
}cro_t;

cro_t createMat(cro_t m)
{
	int mi=0, mj=0, mk=0;
	printf("输入矩阵的行数、列数和非0元素的个数：");
	scanf("%d%d%d", &mi, &mj, &mk);
	m.i = mi;
	m.j = mj;
	m.k = mk;
	m.rhead = (Link_t*)malloc(sizeof(struct Link));
	if(m.rhead == NULL) exit(-1);
	m.chead = (Link_t*)malloc(sizeof(struct Link));
	if(m.chead == NULL) exit(-1);
	for(int i = 1; i <= mi; i++) 
	{
		m.rhead[i] = NULL;
	}
	for(int j = 1; j <= mj; j++) 
	{
		m.chead[j] = NULL;
	}
	int ni=0, nj=0, nk=0;
	link_t* q = NULL;
	for(scanf("%d%d%d", &ni, &nj, &nk); 0 != ni; scanf("%d%d%d", &ni, &nj, &nk))
	{
		link_t* p = (link_t*)malloc(sizeof(struct Link));
		if(p == NULL) exit(-1);
		p->i = ni;
		p->j = nj;
		p->k = nk;
		//链接到行指定位置
		if(NULL == m.rhead[ni] || m.rhead[ni]->j > nj)
		{
			p->right = m.rhead[ni];
			m.rhead[ni] = p;
		}
		else
		{
			for(q = m.rhead[ni]; (q->right)&&q->right->j < nj; q=q->right);
			p->right = q->right;
			q->right = p;
		}
		//链接到列指定位置
		if(NULL == m.chead[nj] || m.chead[nj]->i > ni)
		{
			p->down = m.chead[ni];
			m.chead[nj] = p;
		}
		else
		{
			for(q = m.chead[nj]; (q->down)&&q->down->i < ni; q=q->down);
			p->down = q->down;
			q->down = p;
		}
	}
	return m;
}

void display(cro_t m)
{
	for(int i=1; i <= m.j; i++)
	{
		if(NULL != m.chead[i])
		{
			Link_t p = m.chead[i];
			while(NULL != p)
			{
				printf("%d\t%d\t%d\n", p->i, p->j, p->k);
				p = p->down;
			}
		}
	}
}

int main()
{
	cro_t m;
	m.rhead = NULL;
	m.chead = NULL;
	m = createMat(m);
	display(m);

	return 0;
}
