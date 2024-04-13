#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int list_date_type;

typedef struct list_node
{
	struct list_node* pre;
	struct list_node* next;
	list_date_type val;
}node;

//��ʼ��
void list_init(node** pphead);
//�����½ڵ�
node* creatnewnode();
//β��
void listpushback(node* phead,list_date_type x);
//βɾ
void listpopback(node* phead);
//��ӡ
void listprint(node* phead);
//ͷ��
void listpushfront(node* phead, list_date_type x);
//ͷɾ
void listpopfront(node* phead);
//����
node* listfind(node* phead,list_date_type x);
//�м����(��pos��ǰ�����)
void listinsert(node* phead, list_date_type x);
//�����ڵ�
void listerase(node* phead, list_date_type x);