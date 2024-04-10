#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef int SLDateType;

typedef struct SLNode
{
	SLDateType x;
	struct SLNode* next;
}SLNode;

//��ӡ
void SLprint(SLNode* phead);
//β��
void SLpushback(SLNode** phead, SLDateType x);
//βɾ
void SLpopback(SLNode** phead);
//ͷ��
void SLpushfront(SLNode** phead,SLDateType x);
//ͷɾ 
void SLpopfront(SLNode** pphead);
//����
void FindSLNode(SLNode* phead, SLDateType x);
//�м����
void InsertSLNode(SLNode** pphead,unsigned int SLnum, SLDateType x);
//�м�ɾ��
void EraseSLNode(SLNode** pphead, unsigned int SLnum);
//��ת����
void SLreverse(SLNode** pphead);
//�ͷ�����ռ�
void deleteSL(SLNode** pphead);
//ɾ���������ص���ֵ�Ľڵ�
void SLdeletevalue(SLNode** pphead,SLDateType x);
//�ѱ�ָ��Ԫ��С�ķŵ����,�ѱ�ָ��Ԫ�ش�ķŵ��ұ�
void SLsortx(SLNode** pphead, SLDateType x);
//�����жϻ���
void SLisback(SLNode* phead);