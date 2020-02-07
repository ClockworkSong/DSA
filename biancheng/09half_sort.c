/*************************************************************************
	> File Name: 09half_sort.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Wed Feb  5 20:53:02 2020
 ************************************************************************/

#include <stdio.h>

void print(int a[], int n ,int i){
    printf("%d:",i);
    for(int j=0; j<8; j++){
        printf("%d",a[j]);
    }
    printf("\n");
}

void half_sort(int a[], int size)
{
	int i = 0, j = 0;
	int low = 0, high = 0, mid = 0;
	int tmp = 0;
	for(i = 1;i < size; i++)
	{
		low = 0;
		high = i-1;
		tmp = a[i];
		while(low <= high)
		{
			mid = (low+high)/2;
			if(a[mid]>tmp)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		for(j = i; j > low; j--)
			a[j] = a[j-1];
		a[low] = tmp;//插入元素
		print(a,8,i);
	}

}

void display(int a[])
{
	for(int i = 0; i < 8; i ++)
		printf("%d ", a[i]);
	printf("\n");
}


int main()
{
	int a[8] = {3,1,7,5,2,4,9,6};

	half_sort(a, 8);
	display(a);
	return 0;
}
