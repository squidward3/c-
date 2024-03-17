#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//实现一个函数可以左旋k个字符.

void counter_clockwise(char *begin, int sz,int k)//第一种算法
{
	int i = 0;
	char tmp = 0;
	for (i = 0; i < k; i++)
	{
		tmp = *begin;
		int j = 0;
		for (j = 1; j <= sz- 1; j++)
		{
			*(begin+j-1)= *(begin + j);
		}
		*(begin+sz-1) = tmp;
	}
}												//

void reverse(char* left, char* right)			//第2种算法
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void counter_clockwise2(char* begin, int sz, int k)
{
	reverse(begin, begin + k - 1);
	reverse(begin + k, begin + sz - 1);
	reverse(begin, begin + sz - 1);
}												//		

int main()
{
	char arr[] = "ABCDEFG";
	int sz = strlen(arr);
	int k = 0;
	scanf("%d", &k);
	counter_clockwise2(arr, sz,k);
	printf("%s\n", arr);
	return 0;
}