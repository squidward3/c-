#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()//好掉的算法(快速求出n个数的平均值(排除了最大值和最小值))
{
	int source = 0;
	int sum = 0;
	int max = 0;
	int min = 100;
	int i = 0;
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &source);
		sum = sum + source;
		if (source > max)
		{
			max = source;
		}
		if (source < min)
		{
			min = source;
		}
	}
	printf("%f",(sum-min-max)/5.0);
	return 0;
}