//��ԭ�������Ƴ�һ��Ԫ��||Ҫ��:1.�ռ临�Ӷ�Ϊo(1) 2.ԭ���Ƴ�
//��������Ϊ{1,3,4,3,5,3}�Ƴ�3.
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
	int* arr = arry();//��������
	printarr(arr);//��ӡ��ʼ������
	int i = 0;
	int j = 0;
	int tmp = 0;
	while (i<6)//����2������,��������������±�Ϊ[i]��Ԫ�ظ����±�Ϊ[j]��Ԫ������i��j++,�������������i++ȥѰ����һ����.
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