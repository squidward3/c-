#include <stdio.h>
#include <assert.h>

int my_strcmp(const char* p,const char* q)
{
	assert(p && q);
	while (*p == *q)
	{
		if (*p == '\0')
		{
			return 0;
		}
		p++;
		q++;
	}
	return *p - *q;
}

int main()
{
	char* str1 = "abc";
	char* str2 = "abc";
	int ret = my_strcmp(str1,str2);
	if (ret > 0)
	{
		printf("str1>str2\n");
	}
	else if (ret < 0)
	{
		printf("str1<str2\n");
	}
	else
	{
		printf("str1==str2\n");
	}
	return 0;
}