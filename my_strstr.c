#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strstr(const char* str1,const char* str2)
{
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;
	if (*str2 == '\0')
	{
		return (char*)str1;
	}
	while (*s1++)//++的优先级高于*所以++合s1结合,所有是s1+1,不是(*s1)+1.
	{
		while (*str1 == *str2 && *str1 && *str2 )
		{
			str1++;
			str2++;
			if (*str2 == '\0')
			{
				return (char*)(s1 - 1);
			}
		}
		str1 = s1;
		str2 = s2;
	}
	return NULL;
}

int main()
{
	char arr1[30] = "abbebbcwqewq";
	char arr2[] = "";
	char *ret=my_strstr(arr1, arr2);
	if (ret == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了%s\n", ret);
	}
	return 0;
}