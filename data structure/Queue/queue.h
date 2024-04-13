#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType x;
	struct QueueNode* next;
}Node;

typedef struct Queue
{
	Node* head;
	Node* tail;
}Queue;

//��ʼ������
void QueueInit(Queue** qqp);
//���ٶ���
void QueueDestroy(Queue* qp);
//���
void QueuePush(Queue* qp, QDataType x);
//����
void QueuePop(Queue* qp);
//ȡ��ͷ������
QDataType QueueFront(Queue* qp);
//ȡ��β������
QDataType QueueBack(Queue* qp);
//�ж��Ƿ�����Ƿ�Ϊ��
int QueueEmpty(Queue* qp);
//�ж϶��еĴ�С
int QueueSize(Queue* qp);
