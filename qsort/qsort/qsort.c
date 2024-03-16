#define _CRT_SECURE_WARNINGS 1
#include <stdio.h>

struct gamer
{
	int age;
	char name[20];
};

int cmp1(const void* e1, const void* e2)
{
	return *((int*)e1)-*((int*)e2);
}

int cmp2(const void* e1, const void* e2)
{
	return *(int*)e2 - *(int*)e1;
}

int cmp_gamer_age(const void* e1, const void* e2)
{
	return ((struct gamer*)e1)->age - ((struct gamer*)e2)->age;
}

void printfarr(int arr[],int sz)
{
	int i = 0;
	for (i = 0 ; i < sz  ; i++)
	{
		printf("%d ", arr[i]);
	}
}

void swap(char* buf1, char* buf2,int sz, int size)
{
	int i = 0;
	char tmp = 0;
	for (i = 0; i < size; i++)
	{
		tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* arr, int sz, int size, int (*cmp)( void* e1,void * e2))
{
	int i = 0;
	for (i = 0; i<sz-1; i++)
	{
		int j = 0;
		for (j = 0; j<sz-1-i; j++)
		{
			if (cmp((char*)arr + j * size, (char*)arr + (j + 1) * size)<0)
			{
				swap((char*)arr+j*size,(char*)arr+(j+1)*size, sz, size);
			}
		}
	}
}

int main()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
	struct gamer gamer_table[2] = { {31,"sb"},{21,"shuaib"} };
	int sz_table = sizeof(gamer_table) / sizeof(gamer_table[0]);
	int sz = sizeof(arr) / sizeof(arr[0]);
	printfarr(arr, sz);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp1);
	printf("\n");
	printfarr(arr, sz);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp2);
	printf("\n");
	printfarr(arr, sz);
	bubble_sort(gamer_table, sz_table, sizeof(gamer_table[0]), cmp_gamer_age);
	printf("\n");
	return 0;
}

