#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int HDataType;

typedef struct Heap
{
	HDataType* _a;
	int _size;
	int _capacity;
	int IsBigOrSmall; //-1为普通的完全堆0为小堆1为大堆;
}Heap;

//初始化堆
void HeapInit(Heap*php,HDataType* a, int size);
//摧毁堆
void HeapDestroy(Heap* php);
//向下小堆调整堆
void AdjustDownSmall(Heap* php,int n,int root);
//向下大堆调整堆
void AdjustDownBig(Heap* php, int n, int root);
//创建小堆
void SmallHeapSort(Heap* php);
//创建大堆
void BigHeapSort(Heap* php);
//小堆的降序排序
void DescendSort(Heap*php);
//大堆的升序排列
void AscendSort(Heap* php);
//往堆里面插入数据(尾插)
void HeapPush(Heap* php, HDataType x);
//删除堆头的元素
HDataType HeapPop(Heap* php);
//取堆头元素的值
HDataType HeapTop(Heap* php);
//便于调试的接口
void print(Heap* php);