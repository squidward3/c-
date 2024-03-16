#define _CRT_SECUER_WARNINGS 1
#include <stdio.h>

int find_num(int arr[3][3], int* px, int* py, int k)
{
	int x = 0;
	int y = *py-1;
	while (x < *px && y >= 0)
	{
		if (arr[x][y] < k)
		{
			x++;
		}
		else if (arr[x][y] > k)
		{
			y--;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 13;
	int x = 3;
	int y = 3;
	if (find_num(arr, &x, &y, k) == 1)
	{
		printf("找到了:%d %d\n",x,y);
	}
	else 
	{
		printf("没找到!");
	}

	return 0;
}