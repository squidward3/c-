#include "Heap.h"

void Text1()
{
	int a[] = { 27,15,19,18,28,34,65,49,25,37 }; //给的数据
	Heap php ;
	HeapInit(&php,a,sizeof(a)/sizeof(a[0]));
	BigHeapSort(&php);
	print(&php);
	HeapPush(&php, 13);
	print(&php);
	HeapDestroy(&php);
}

int main()
{
	Text1();
	return 0;
}