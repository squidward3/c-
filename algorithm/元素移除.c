//在原数组上移除一个元素||要求:1.空间复杂度为o(1) 2.原地移除
//例子数组为{1,3,4,3,5,3}移除3.
#include <stdio.h>
#include <stdlib.h>

void printarr(int* arr)
{
	int i = 0;
	for (i = 0; i < 6; i++ )
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int* arry()
{
	int i = 0;
	int* arr = (int*)malloc(sizeof(int) * 6);
	arr[0] = 1;
	arr[1] = 3;
	arr[2] = 4;
	arr[3] = 3;
	arr[4] = 5;
	arr[5] = 3;
	return arr;
}

int main()
{
	int* arr = arry();//创建数组
	printarr(arr);//打印开始的数组
	int i = 0;
	int j = 0;
	int tmp = 0;
	while (i<6)//创建2个变量,如果等于三则让下表为[i]的元素覆盖下标为[j]的元素再让i和j++,如果不等于则让i++去寻找下一个三.
	{
		if (arr[i] != 3)
		{
			tmp = arr[i];
			arr[i] = 0;
			arr[j] = tmp;
			j++;
			i++;
		}
		if (arr[i] == 3)
		{
			arr[i] = 0;
			i++;
		}
	}
	printarr(arr);
	free(arr);
	arr = NULL;
	return 0;
}