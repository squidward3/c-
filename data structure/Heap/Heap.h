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
	int IsBigOrSmall; //-1Ϊ��ͨ����ȫ��0ΪС��1Ϊ���;
}Heap;

//��ʼ����
void HeapInit(Heap*php,HDataType* a, int size);
//�ݻٶ�
void HeapDestroy(Heap* php);
//����С�ѵ�����
void AdjustDownSmall(Heap* php,int n,int root);
//���´�ѵ�����
void AdjustDownBig(Heap* php, int n, int root);
//����С��
void SmallHeapSort(Heap* php);
//�������
void BigHeapSort(Heap* php);
//С�ѵĽ�������
void DescendSort(Heap*php);
//��ѵ���������
void AscendSort(Heap* php);
//���������������(β��)
void HeapPush(Heap* php, HDataType x);
//ɾ����ͷ��Ԫ��
HDataType HeapPop(Heap* php);
//ȡ��ͷԪ�ص�ֵ
HDataType HeapTop(Heap* php);
//���ڵ��ԵĽӿ�
void print(Heap* php);