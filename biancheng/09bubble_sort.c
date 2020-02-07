/*************************************************************************
	> File Name: 09bubble_sort.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Wed Feb  5 21:37:41 2020
 ************************************************************************/

#include <stdio.h>

void bubbleSort(int a[], int size)
{
	int i, j, tmp;
	for(i = 0;i < size-1;i ++)
	{
		for(j=0; j < size-1-i; j++)
		{
			if(a[j] > a[j+1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}

void dispaly(int a[])
{
	for(int i = 0; i < 8; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int arr[8] = {3, 1, 5, 7, 9, 2, 4, 6};
	bubbleSort(arr, 8);
	dispaly(arr);
}
