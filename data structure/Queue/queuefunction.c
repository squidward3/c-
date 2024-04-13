#include "queue.h"

void QueueInit(Queue** qqp)
{
	*qqp = (Queue*)malloc(sizeof(Queue));
	if (*qqp == NULL)
	{
		printf("空间不足\n");
		exit(-1);
	}
	(*qqp)->head = (*qqp)->tail = NULL;
	return;
}

void QueuePush(Queue* qp, QDataType x)
{
	assert(qp);
	if (qp->head == NULL)
	{
		qp->head = qp->tail = (Node*)malloc(sizeof(Node));
		if (qp->head == NULL)
		{
			printf("内存不足\b");
			exit(-1);
		}
		qp->head->next = NULL;
		qp->tail->next = NULL;
		qp->head->x = x;
		return;
	}
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode == NULL)
	{
		printf("内存不足\n");
		exit(-1);
	}
	qp->tail->next = NewNode;
	qp->tail = NewNode;
	qp->tail->next = NULL;
	qp->tail->x = x;
	return;
}

void QueuePop(Queue* qp)
{
	assert(qp);
	Node* tmp = qp->head->next;
	if (tmp == NULL)
	{
		free(qp->head);
		qp->head = NULL;
		return;
	}
	free(qp->head);
	qp->head = tmp;
	return;
}

void QueueDestroy(Queue* qp)
{
	assert(qp);
	Node* cur = qp->head;
	while (cur)
	{
		Node* next = cur->next;
		free(cur);
		cur = cur->next;
	}
	qp->head = NULL;
	qp->tail = NULL;
	return;
}

QDataType QueueFront(Queue* qp)
{
	assert(qp);
	assert(qp->head);
	return qp->head->x;
}

QDataType QueueBack(Queue* qp)
{
	assert(qp);
	assert(qp->tail);
	return qp->tail->x;
}

int QueueEmpty(Queue* qp)
{
	assert(qp);
	return qp->head==NULL?1:0;
}

int QueueSize(Queue* qp)
{
	int ret = 0;
	Node* cur = qp->head;
	while (cur)
	{
		cur = cur->next;
		ret += 1;
	}
	return ret;
}
