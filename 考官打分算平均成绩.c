#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()//�õ����㷨(�������n������ƽ��ֵ(�ų������ֵ����Сֵ))
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