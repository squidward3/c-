#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define initcount 4

typedef int sltype;

typedef struct sequencelist
{
	sltype* arry;
	int size;
	int capacity;
}SL;

//����Ƿ�Ҫ��ӿռ�
void checkslmemory(SL* ps);
//��ʼ��
void slinit(SL*ps);
//��ӡ˳���
void printsl(SL* ps);
//β��
void slpushback(SL* ps, sltype x);
//βɾ
void slpopback(SL*ps);
//ͷ��
void slpushfront(SL* ps, sltype x);
//ͷɾ
void slpopfront(SL* ps);
//�м����(����)
void slinsert(SL* ps,const unsigned int pos,const sltype x);
//�м�ɾ�� 
void slerase(SL* ps, unsigned int pos);
//����
void slfind(SL* ps);
//����
void slsort(SL* ps);
//����˳���
void sldestroy(SL* ps);
