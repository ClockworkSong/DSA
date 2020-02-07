/*************************************************************************
	> File Name: 09insert_sort.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Wed Feb  5 20:08:15 2020
 ************************************************************************/

#include <stdio.h>

#define SIZE 8

void insertSort(int a[], int size)
{
	for(int i = 1; i < size; i++)
	{
		int tmp = a[i];
		int j = i - 1;
		while(j >= 0 && tmp < a[j])
		{
			a[j+1] = a[j];
			j --;
		}
		a[j+1] = tmp;
	}
}

void display(int a[])
{
	for(int i = 0; i < SIZE; i ++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int arr[SIZE] = {3, 1, 7, 5, 2, 4, 9, 6};
	insertSort(arr, SIZE);
	display(arr);
	return 0;
}
