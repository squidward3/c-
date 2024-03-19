#define _CRT_SECURER_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

void my_memset(void* dest ,  void* src,size_t num)
{
	assert(dest && src);
	if (src <= dest)
	{
		while (num--)
		{
			*((char*)dest + num ) = *((char*)src + num );
		}
	}
	if (src > dest)
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
}

int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };
	my_memset(arr1+2,arr1, 20);
	return 0;

}