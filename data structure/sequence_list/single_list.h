#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef int SLDateType;

typedef struct SLNode
{
	SLDateType x;
	struct SLNode* next;
}SLNode;

//打印
void SLprint(SLNode* phead);
//尾插
void SLpushback(SLNode** phead, SLDateType x);
//尾删
void SLpopback(SLNode** phead);
//头插
void SLpushfront(SLNode** phead,SLDateType x);
//头删 
void SLpopfront(SLNode** pphead);
//查找
void FindSLNode(SLNode* phead, SLDateType x);
//中间插入
void InsertSLNode(SLNode** pphead,unsigned int SLnum, SLDateType x);
//中间删除
void EraseSLNode(SLNode** pphead, unsigned int SLnum);
//反转链表
void SLreverse(SLNode** pphead);
//释放链表空间
void deleteSL(SLNode** pphead);
//删除链表中特点数值的节点
void SLdeletevalue(SLNode** pphead,SLDateType x);
//把比指定元素小的放到左边,把比指定元素大的放到右边
void SLsortx(SLNode** pphead, SLDateType x);
//链表判断回文
void SLisback(SLNode* phead);