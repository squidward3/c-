#include "single_list.h"

void SLpushback(SLNode** phead, SLDateType x)
{
	//�������Ϊ�������һ������
	if ((*phead) == NULL)
	{
		(*phead) = (SLNode*)malloc(sizeof(SLNode));
		if (*phead == NULL)
		{
			printf("�����ڴ�ռ�ʧ��\n");
			exit(-1);
		}
		(*phead)->next = NULL;
		(*phead)->x = x;
		return;
	}
	else
	{
		//�����Ϊ�������ҵ�β��
		SLNode* NewNode = (*phead);
		SLNode* before = NULL;//before��ĩβ������ָ��
		while (NewNode!=NULL)
		{
			before = NewNode;
			NewNode = NewNode->next;
		}
		NewNode = (SLNode*)malloc(sizeof(SLNode));
		if (NewNode == NULL)
		{
			printf("�ڴ�����ʧ��\n");
			exit(-1);
		}
		before->next = NewNode;
		NewNode->x = x;
		NewNode->next = NULL;
	}
}

void SLprint(SLNode* phead)
{
	if (phead == NULL)
	{
		printf("û��Ԫ�ؿ��Դ�ӡ\n");
		return;
	}
	else
	{
		SLNode* cur = phead;
		while (cur != NULL)
		{
			printf("%d->", cur->x);
			cur = cur->next;
		}
		printf("NULL\n");
	}
}

void SLpopback(SLNode** phead)
{
	if ((*phead) == NULL)
	{
		printf("û��Ԫ�ؿ���ɾ��\n");
		return;
	}
	else if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
		return;
	}
	else
	{
		SLNode* before = NULL;
		SLNode* cur = *phead;
		while (cur != NULL)
		{
			before = cur;
			cur = cur->next;
			if (cur->next == NULL)
			{
				break;
			}
		}
		free(cur);
		cur = NULL;
		before->next = NULL;
		return;
	}
}

void SLpushfront(SLNode** phead, SLDateType x)
{
	if ((*phead) == NULL)
	{
		(*phead) = (SLNode*)malloc(sizeof(SLNode));
		if (*phead == NULL)
		{
			printf("�����ڴ�ռ�ʧ��\n");
			exit(-1);
		}
		(*phead)->next = NULL;
		(*phead)->x = x;
		return;
	}
	else
	{
		SLNode* next = *phead;
		(*phead) = (SLNode*)malloc(sizeof(SLNode));
		if (*phead == NULL)
		{
			printf("�����ڴ�ռ�ʧ��\n");
			exit(-1);
		}
		(*phead)->next = next;
		(*phead)->x = x;
		return;
	}
}

void SLpopfront(SLNode** pphead)
{
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLNode * tmp = (*pphead)->next;
		free(*pphead);
		*pphead=tmp;
		return;
	}
} 

void FindNode(SLNode*phead,SLDateType x)
{
	if (phead == NULL)
	{
		printf("û�ÿɲ�����Ԫ��.\n");
		return;
	}
	else 
	{
		int i = 1;
		SLNode* cur = phead;
		while (cur->x != x)
		{
			cur = cur->next;
			i++;
		}
		printf("�ҵ���,�ǵ�:%d��Ԫ��", i);
	}
}

void InsertSLNode(SLNode** pphead,unsigned int SLnum,SLDateType x)
{
	//����ڵ����:
	SLNode* cur = *pphead;
	unsigned int num = 0;
	while (cur != NULL)
	{
		cur = cur->next;
		num++;
	}

	if (SLnum>num||num==0)
	{
		printf("������Χ,ȡ���������\n");
		return;
	}
	else if (num==1)
	{
		(*pphead)->next = (SLNode*)malloc(sizeof(SLNode));
		if ((*pphead)->next == NULL)
		{
			printf("����ռ�ʧ��\n");
			exit(-1);
		}
		(*pphead)->next->x = x;
		(*pphead)->next->next = NULL;
		return;
	}
	else
	{
		//���ҵ�Ҫ�����λ��.
		SLNode* pos = *pphead;
		while (SLnum - 1)
		{
			pos = pos->next;
			SLnum--;
		}
		SLNode* tmp = pos->next;
		SLNode* Next = (SLNode*)malloc(sizeof(SLNode));
		if (Next == NULL)
		{
			printf("����ռ�ʧ��\n");
			exit(-1);
		}
		pos->next = Next;
		Next->x = x;
		Next->next = tmp;
		printf("����ɹ�\n");
		return;
	}
}

void EraseSLNode(SLNode** pphead, unsigned int SLnum)
{
	SLNode* cur = *pphead;
	unsigned int num = 0;
	while (cur != NULL)
	{
		cur = cur->next;
		num++;
	}
	if (SLnum > num || num == 0)
	{
		printf("������Χ,ȡ����������\n");
		return;
	}
	else if (num==1)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else if (num==2)
	{
		if (SLnum == 1)
		{
			SLpopfront(pphead);
		}
		else
		{
			SLpopback(pphead);
		}
	}
	else
	{
		SLNode* pos = *pphead;
		SLNode* perv = NULL;
		while (SLnum - 1)
		{
			perv = pos;
			pos = pos->next;
			SLnum--;
		}
		SLNode* next = pos->next;
		free(pos);
		pos = NULL;
		perv->next = next;
		return;
	}
}

void deleteSL(SLNode** pphead)
{
	if (*pphead == NULL)
	{
		printf("ʧ��\n");
		return;
	}
	SLNode* cur = (*pphead);
	SLNode* next = (*pphead)->next;
	while (next)
	{
		free(cur);
		cur = next;
		next = next->next;
	}
	cur = NULL;
	return;
}

/*void SLreverse(SLNode** pphead)//�Լ������������
{
	if ((*pphead)->next == NULL||*pphead==NULL)
	{
		printf("ʧ��!\n");
		return;
	}
	SLNode* tmp = *pphead;
	SLNode* Newhead = NULL;
	while (tmp)
	{
		SLpushfront(&Newhead, tmp->x);
		tmp = tmp->next;
	}
	deleteSL(pphead);
	*pphead = Newhead;
	return ;
}*/

void SLreverse(SLNode** pphead)//��+�Լ��Ľ���
{
	if ((*pphead)->next == NULL || *pphead == NULL)
	{
		printf("ʧ��!\n");
		return;
	}
	SLNode* cur = *pphead;
	SLNode* next = (*pphead)->next;
	SLNode* Newhead = NULL;
	while (1)
	{
		cur->next = Newhead;
		Newhead = cur;
		cur = next;
		if (next == NULL)
		{
			break;
		}
		next = next->next;
	}
	*pphead = Newhead;
	return;
}

void SLdeletevalue(SLNode** pphead, SLDateType x)
{
	if (*pphead == NULL)
	{
		printf("ʧ��\n");
		return;
	}
	SLNode* cur = *pphead;
	SLNode* next = (*pphead)->next;
	SLNode* tmp = NULL;
	while (next)
	{
		if (next->x != x)
		{
			cur = cur->next;
			next = next->next;
		}
		else
		{
			tmp = next->next;
			free(next);
			cur->next = tmp;
			next = tmp;
		}
	}
	return;
}

void SLsortx(SLNode** pphead, SLDateType x)
{
	if (*pphead == NULL || (*pphead)->next == NULL)
	{
		printf("ʧ��\n");
		return;
	}
	SLNode* lesshead, * lesstail;
	SLNode* greaterhead, * greatertail;
	lesshead = lesstail = (SLNode*)malloc(sizeof(SLNode));
	greaterhead = greatertail = (SLNode*)malloc(sizeof(SLNode));
	lesstail->next = NULL;
	greatertail->next = NULL;
	SLNode* cur = *pphead;
	while (cur)
	{
		if (cur->x < x)
		{
			lesstail->next = cur;
			lesstail = lesstail->next;
		}
		else
		{
			greatertail->next = cur;
			greatertail = greatertail->next;
		}
		cur = cur->next;
	}
	lesstail->next = greaterhead->next;
	greatertail->next = NULL;
	*pphead = lesshead->next;
	free(greaterhead);
	free(lesshead);
	greaterhead = NULL;
	lesshead = NULL;
	return;
}

void SLisback(SLNode* phead)//���Ż�(�ı��ԭ������Ľṹ���һ�����ڴ�й©����)
{
	//�������ÿ���ָ���ҵ��м���ֵ
	SLNode* head = phead;
	SLNode* cur = phead;
	SLNode* prev = phead;
	SLNode* prepre = NULL;
	while (cur != NULL && cur->next != NULL)
	{
		prepre = prev;
		prev = prev->next;
		cur = cur->next->next;
	}
	//��ת����
	SLNode* bg = NULL;
	if (cur == NULL)
	{
		bg = prev;
		prepre->next = NULL;
	}
	else
	{
		bg = prev->next;
		prepre->next = NULL;
	}
	SLNode* next = bg->next;
	SLNode* prew = NULL; 
	while (1)    
	{
		bg->next = prew;
		prew = bg;
		bg = next;
		if (next == NULL)
		{
			break;
		}
		next = next->next;
	}
	//���ĵ��ж�
	while (head!=NULL&&prew!=NULL)
	{
		if (head->x == prew->x)
		{
			;
		}
		else
		{
			printf("���ǻ��Ľṹ\n");
			return;
		}
		head = head->next;
		prew = prew->next;
	}
	printf("�ǻ��Ľṹ\n");
}