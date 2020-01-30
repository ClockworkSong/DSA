/*************************************************************************
	> File Name: 06three_tuple.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Fri Jan 31 15:38:10 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//三元组结构体
typedef struct Triple
{
	int i, j;//行标i列标j
	int data;//元素值
}tri_t;

#define NUMER 20

//矩阵的结构表示
typedef struct Matrix
{
	tri_t arr[NUMER];//存储该矩阵中所有非0元素的三元组
	int i, j, n;//分别记录矩阵的行数、列数和非零元素个数
}mat_t;


void display(mat_t* m)
{
	for(int i = 1; i <= (*m).i; i++)
	{
		for(int j = 1; j <= (*m).j; j++)
		{
			int flag = 0;
			for(int k = 0; k <= (*m).n; k++)
			{
				if(i == (*m).arr[k].i && j == (*m).arr[k].j)
				{
					printf("%d ", (*m).arr[k].data);
					flag = 1;
					break;
				}
			}
			if(flag == 0) printf("%d ", flag);
		}
	printf("\n");
	}
}

int main()
{
	mat_t m;
	m.i = 3;
	m.j = 3;
	m.n = 3;

	m.arr[0].i = 1;
	m.arr[0].j = 1;
	m.arr[0].data = 1;
	
	m.arr[1].i = 2;
	m.arr[1].j = 3;
	m.arr[1].data = 5;
	
	m.arr[2].i = 3;
	m.arr[2].j = 1;
	m.arr[2].data = 3;
	
	display(&m);
	
	return 0;
}

