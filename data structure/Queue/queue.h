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

//初始化队列
void QueueInit(Queue** qqp);
//销毁队列
void QueueDestroy(Queue* qp);
//入队
void QueuePush(Queue* qp, QDataType x);
//出队
void QueuePop(Queue* qp);
//取出头的数据
QDataType QueueFront(Queue* qp);
//取出尾的数据
QDataType QueueBack(Queue* qp);
//判断是否队列是否为空
int QueueEmpty(Queue* qp);
//判断队列的大小
int QueueSize(Queue* qp);
