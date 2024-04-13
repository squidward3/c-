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

//初始化
void list_init(node** pphead);
//创建新节点
node* creatnewnode();
//尾插
void listpushback(node* phead,list_date_type x);
//尾删
void listpopback(node* phead);
//打印
void listprint(node* phead);
//头插
void listpushfront(node* phead, list_date_type x);
//头删
void listpopfront(node* phead);
//查找
node* listfind(node* phead,list_date_type x);
//中间插入(在pos的前面插入)
void listinsert(node* phead, list_date_type x);
//擦除节点
void listerase(node* phead, list_date_type x);