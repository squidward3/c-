#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

int is_string_rotation(char* str1, char* str2)
{
	assert(str1);
	assert(str2);
	if (strlen(str1) != strlen(str2))
	{
		return 0;
	}
	int len = strlen(str1);
	strncat(str1, str1, len);
	char*ret = strstr(str1, str2);
	return (int)ret;
}

int main()
{
	char arr1[50] = "AABBCCDDEEFF";
	char arr2[50] = "DDAAEEFFAABB";
	int ret = is_string_rotation(arr1, arr2);
	if (ret == 0)
	{
		printf("没有找到\n");
	}
	else
	{
		printf("找到了\n");
	}
	return 0;
}