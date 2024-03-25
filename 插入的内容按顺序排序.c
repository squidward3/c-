#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include<stdlib.h>

void bubble_sort(int*p,int count)
{
	int j = 0;
	int i = 0;
	int tmp = 0;
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - i-1; j++)
		{
			if (*(p + j) > *(p + j + 1))
			{
				tmp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = tmp;
			}
		}
	}
}

void print_sort(int* p, int count)
{
	int i = 0;
	for (i = 0; i < count; i++)
	{
		printf("%d ", *(p + i));
	}
}


int main()
{
	int count = 0;
	int numb = 0;
	int i = 0;
	int j = 0;
	int tmp = 0;
	scanf("%d", &count);
	int * p=(int*)calloc(count+2, sizeof(int));
	for (i=0; i < count;i++)
	{
		scanf("%d", p + i);
	}
	bubble_sort(p,count);
	print_sort(p,count);
	printf("请输入要插入的数字");
	scanf("%d", &numb);
	for (i = 1; i < count; i++)
	{
		if (*(p + i-1) < numb && *(p + i) > numb)
		{
			for (j = 0; j < count - i ; j++)
			{
				*(p + count - j)= *(p + count - 1 - j);
			}
			*(p + i) = numb;
		}
		if (numb < *p)
		{
			for (j = 0; j < count ; j++)
			{
				*(p + count - j)= *(p + count - 1 - j);
			}
			*p = numb;
		}
	}
	if (numb > *(p + count - 1))
	{
		*(p + count) = numb;
	}
	print_sort(p, count + 1);
	free(p);
	p = NULL;
	return 0;
}