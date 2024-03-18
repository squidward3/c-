#define _CRT_SERCURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

void* my_memcpy(void* str1, const void* str2,int num)
{
	assert(str1 && str2);
	void* tmp = str1;
	while (num--)
	{
		*(char*)str1 = *(char*)str2;
		str1 = (char*)str1 + 1;
		str2 = (char*)str2 + 1;
	}
	return tmp;
}

int main()
{
	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int arr2[20] = { 0 };
	my_memcpy(arr2, arr1,20);
	return 0;
}