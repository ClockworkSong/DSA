/*************************************************************************
	> File Name: 06transpose.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Fri Jan 31 20:12:07 2020
 ************************************************************************/

#include <stdio.h>
#define NUMBER 10

typedef struct Triple
{
	int i, j;
	int data;
}tri_t;

typedef struct Matrix
{
	tri_t arr[NUMBER];
	int n, m, num;
}mat_t;


mat_t transpose(mat_t m, mat_t t)
{
	t.m = m.n;
	t.n = m.m;
	t.num = m.num;

	int q = 0;
	if(t.num)
	{
		for(int i = 1; i <= m.m; i++)
		{
			for(int j = 0; j < m.num; j++)
			{
				if(m.arr[j].j == i)
				{
					t.arr[q].i = m.arr[j].j;
					t.arr[q].j = m.arr[j].i;
					t.arr[q].data = m.arr[j].data;
					q++;
				}
			}
		}
	}
	return t;
}

void display(mat_t t)
{
	for(int i = 0; i < t.num; i++)
	{
		printf("(%d,%d,%d)\n", t.arr[i].i, t.arr[i].j, t.arr[i].data);
	}
}

int main()
{
	mat_t m;
	m.m = 2;
	m.n = 3;
	m.num = 4;

	printf("矩阵转置前:\n");
	m.arr[0].i = 1;
	m.arr[0].j = 2;
	m.arr[0].data = 1;
	
	m.arr[1].i = 2;
	m.arr[1].j = 2;
	m.arr[1].data = 3;
	
	m.arr[2].i = 3;
	m.arr[2].j = 1;
	m.arr[2].data = 6;

	m.arr[3].i = 3;
	m.arr[3].j = 2;
	m.arr[3].data = 5;
	display(m);
	printf("矩阵转置后:\n");
	mat_t t;
	t = transpose(m, t);
	display(t);

	return 0;
}
