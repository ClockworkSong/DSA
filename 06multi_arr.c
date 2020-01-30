/*************************************************************************
	> File Name: 06multi_arr.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Thu Jan 30 13:48:36 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>//va_list解决变参问题

#define SIZE 8
#define OVERFLOW 3
#define UNDERFLOW 4

typedef struct Array
{
	int* base;//数组元素基地址
	int dim;//数组维数
	int* bounds;//数组维基界址
	int* constants;//数组映象函数常量基址
}arr_t;

int initArray(arr_t* a, int d, .../*int b1, int b2, int b3*/)
{
	//若维数d和各维长度合法，则构造相应的数组a
	if(d < 1 || d > SIZE) return false;
	(*a).dim = d;
	(*a).bounds = (int*)malloc(d*sizeof(int));
	if((*a).bounds == NULL) exit(OVERFLOW);
	int i = 0;
	int TotalElem = 1;//元素总值
	va_list ap;//定义一个具有va_list型的变量
	va_start(ap, d);//第一个参数指向可变列表的地址，地址自动增加
	for(i = 0; i < d; i ++)
	{
		(*a).bounds[i] = va_arg(ap, int);//va_arg第一个参数是可变参数的地址，第二个参数是传入参数的类型，返回值就是va_list中接着的地址值，类型和va_arg的第二个参数一样
		if((*a).bounds[i] < 0) return UNDERFLOW;
		TotalElem *= (*a).bounds[i];
	}
	printf("TotalElem=%d\n", TotalElem);
	va_end(ap);
	//数组元素首地址
	(*a).base = (int*)malloc(TotalElem*sizeof(int));
	if((*a).base == NULL) exit(OVERFLOW);
	//数组映像函数常量基址
	(*a).constants = (int*)malloc(d*sizeof(int));
	if((*a).constants == NULL) exit(OVERFLOW);
	(*a).constants[d - 1] = 1;//c[2]=1
	for(i = d-2;i >= 0; i--)//c[1]=b[2]*c[2]=2*1, c[0]=b[1]*c[1]=4*2*1
	{
		(*a).constants[i] = (*a).bounds[i+1] * (*a).constants[i+1];
	}

	return true;
}

int Locate(arr_t* a, va_list ap, int* of)
{
	//若ap指示的各下标值合法，则求出该元素在a中的相对地址of
	*of = 0;
	int ind = 0;
	for(int i = 0; i < (*a).dim; i++)
	{
		ind = va_arg(ap, int);
		if(ind < 0 || ind >= (*a).bounds[i]) return OVERFLOW;
		*of += (*a).constants[i]*ind;
	}
	return true;
}

int Assign(arr_t* a, int e, ...)
{
	//依次为各维的下标值，若下标合法，则将e的值赋值给a的指定元素
	int of = 0;
	va_list ap;
	va_start(ap, e);
	int r = Locate(a, ap, &of);//调用Locate()
	if(r == OVERFLOW) return r; 
	*((*a).base + of) = e;
	va_end(ap);
	return true;
}

int Value(int* e, arr_t a, ...)//...之前的形参不能是引用类型
{
	//依次为各维的下标值，若下标合法，则将e的值赋值给a的指定元素
	int of = 0;
	va_list ap;
	va_start(ap, a);
	int r = Locate(&a, ap, &of);//调用Locate()
	if(r == OVERFLOW) return r; 
	*e = *(a.base + of);
	va_end(ap);
	return true;
}

int main()
{
	arr_t a;
	int d=3, b1=3, b2=4, b3=2;//a[3][4][2]数组
	int r = initArray(&a, d, b1, b2, b3);//构造3*4*2的三维数组
	if(r != true) 
	{
		printf("ERROR=%d\n", r);
		exit(-1);
	}
	int* p;
	p = a.bounds;
	printf("a.bounds=");
	for(int i = 0; i < d; i++)//顺序输出a.bounds
	{
		printf("%d ", *(p+i));
	}
	printf("\n");
	int* q;
	q = a.constants;
	printf("q.constants=");
	for(int i = 0; i < d; i++)//顺序输出q.constants
	{
		printf("%d ", *(q+i));
	}
	printf("\n");
	int elem = 0;
	printf("%d页%d行%d列矩阵元素如下:\n", b1, b2, b3);
	for(int i = 0; i < b1; i ++)
	{
		for(int j = 0; j < b2; j ++)
		{
			for(int k = 0; k < b3; k ++)
			{
				Assign(&a, i*100+j*10+k, i, j, k);//将i*100+j*10+k赋值给a[i][j][k]
				Value(&elem, a, i, j, k);//将a[i][j][k]的值赋给elem
				printf("a[%d][%d][%d]=%2d ", i, i, k, elem);
			}
			printf("\n");
		}
		printf("\n");
	}

	int* n = a.base;
	printf("a.base=");
	for(int i = 0; i < b1*b2*b3; i ++)
	{
		printf("%4d", *(n + i));
	}
	printf("\n");
	//Destroy();//销毁数组
	
	return 0;
}

