#include "list.h"

void list_init(node** pphead)
{
	*pphead = (node*)malloc(sizeof(node));
	if (*pphead == NULL)
	{
		exit(-1);
	}
	(*pphead)->next = *pphead;
	(*pphead)->pre = *pphead;
}

node* creatnewnode()
{
	node* newnode = (node*)malloc(sizeof(node));
	if (newnode == NULL)
	{
		exit(-1);
	}
	return newnode;
}

void listpushback(node* phead,list_date_type x)
{
	node*newnode=creatnewnode();
	newnode->pre= phead->pre ;
	phead->pre->next = newnode;
	newnode->next = phead;
	phead->pre = newnode;
	newnode->val = x;
	return;
}

void listpopback(node* phead)
{
	if (phead->next == phead)
	{
		printf("删光了没有可以删除的了\n");
		return;
	}
	node* tmp = phead->pre->pre;
	free(phead->pre);
	tmp->next = phead;
	phead->pre = tmp;
	return;
}

void listprint(node* phead)
{
	node* tmp = phead->next;
	while (tmp != phead)
	{
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
	return;
}

void listpushfront(node* phead,list_date_type x)
{
	node* tmp = phead->next;
	node* newnode = creatnewnode();
	newnode->next = tmp;
	tmp->pre = newnode;
	phead->next = newnode;
	newnode->pre = phead;
	newnode->val = x;
	return;
}

void listpopfront(node* phead)
{
	if (phead->next == phead)
	{
		printf("没有可以删除的了\n");
		return;
	}
	node* first = phead->next;
	node* second = first->next;
	free(first);
	phead->next = second;
	second->pre = phead;
	return;
}

node* listfind(node* phead,list_date_type x)
{
	node* cur = phead->next;
	while (cur->val != x && cur != phead)
	{
		cur = cur->next;

	}
	if (cur != phead)
	{
		return cur;
	}
	return NULL;
}

void listinsert(node* phead, list_date_type x,list_date_type y)
{
	if (phead->next == phead)
	{
		listpopback(phead, x);
		return;
	}
	node*pos=listfind(phead, y);
	if (pos == NULL)
	{
		return;
	}
	node* newnode = creatnewnode();
	node* pos_prev = pos->pre;
	pos_prev->next = newnode;
	newnode->pre = pos_prev;
	newnode->next = pos;
	pos->pre = newnode;
	newnode->val = x;
	return;
}

void listerase(node* phead, list_date_type x)
{
	if (phead->next == phead)
	{
		printf("无元素可以删除\n");
		return;
	}
	node* pos = listfind(phead, x);
	node* pos_prev = pos->pre;
	node* pos_next = pos->next;
	free(pos);
	pos_prev->next = pos_next;
	pos_next->pre = pos_prev;
	return;
}