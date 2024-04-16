#include "Heap.h"

void swap(HDataType* a, HDataType* b)
{
	HDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

void HeapInit(Heap*php,HDataType* a, int size)
{
	assert(php);
	assert(a);
	php->_a = (HDataType*)malloc(sizeof(HDataType) * size);
	if (php->_a == NULL)
	{
		printf("内存不够\n");
		exit(-1);
	}
	memcpy(php->_a, a, sizeof(HDataType) * size);
	php->_size = size;
	php->_capacity = size;
	php->IsBigOrSmall = -1;
}

void HeapDestroy(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_capacity = 0;
	php->_size = 0; 
	php->IsBigOrSmall = -1;
}

void AdjustDownSmall(Heap* php,int n,int root)
{
	assert(php);
	assert(root >= 0);
	assert(n > 0);
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1 < n && php->_a[child] > php->_a[child + 1])
		{
			child++;
		}
		if (php->_a[parent] > php->_a[child])
		{
			swap(&php->_a[parent],&php->_a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustDownBig(Heap* php, int n, int root)
{
	assert(php);
	assert(root >= 0);
	assert(n > 0);
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && php->_a[child] < php->_a[child + 1])
		{
			child++;
		}
		if (php->_a[parent] < php->_a[child])
		{
			swap(&php->_a[parent], &php->_a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void SmallHeapSort(Heap* php)
{
	assert(php);
	int n = php->_size;
	for (int i = (n - 2)/2;i>=0;i--)
	{
		AdjustDownSmall(php, n, i);
	}
	php->IsBigOrSmall = 0;
}

void BigHeapSort(Heap* php)
{
	assert(php);
	int n = php->_size;
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDownBig(php, n, i);
	}
	php->IsBigOrSmall = 1;
}

//小堆降序
void DescendSort(Heap* php)
{
	assert(php);
	SmallHeapSort(php, php->_size);
	for (int i = php->_size - 1; i>0; i--)
	{
		swap(&php->_a[0], &php->_a[i]);
		AdjustDownSmall(php, i, 0);
	}
	php->IsBigOrSmall = -1;
}

//大堆升序
void AscendSort(Heap* php)
{
	assert(php);
	BigHeapSort(php, php->_size);
	for (int i = php->_size - 1; i > 0; i--)
	{
		swap(&php->_a[0], &php->_a[i]);
		AdjustDownBig(php, i, 0);
	}
	php->IsBigOrSmall = -1;
}

void HeapPush(Heap* php, HDataType x)
{
	assert(php);
	php->_size++;
	if (php->_size > php->_capacity)
	{
		php->_capacity *= 2;
		php->_a=(HDataType*)realloc(php->_a,php->_capacity*(sizeof(HDataType)));
		if (php->_a == NULL)
		{
			printf("空间不足\n");
			exit(-1);
		}
	}
	php->_a[php->_size - 1] = x;
	int parent = (php->_size - 2) / 2;
	int child = php->_size - 1;
	if (php->IsBigOrSmall == 0)//小堆
	{
		while (php->_a[parent] > php->_a[child])
		{
			swap(&php->_a[parent], &php->_a[child]);
			child = parent;
			if (parent == 0)
			{
				break;
			}
			parent = (child - 1) / 2;
		}
		return;
	}
	else if (php->IsBigOrSmall == 1)//大堆
	{
		while (php->_a[parent] < php->_a[child])
		{
			swap(&php->_a[parent], &php->_a[child]);
			child = parent;
			if (parent == 0)
			{
				break;
			}
			parent = (child - 1) / 2;
		}
		return;
	}
	else
	{
		return;
	}
}

HDataType HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);
	swap(&php->_a[0], &php->_a[php->_size - 1]);
	if (php->IsBigOrSmall == 0)//小堆
	{
		AdjustDownSmall(php, php->_size - 1, 0);
	}
	else if (php->IsBigOrSmall == 1)//大堆
	{
		AdjustDownBig(php, php->_size - 1, 0);
	}
	php->_size--;
	return php->_size;
}

HDataType HeapTop(Heap* php)
{
	assert(php);
	return php->_a[0];
}

void print(Heap* php)
{
	assert(php);
	;
}