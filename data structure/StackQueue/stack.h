#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;

typedef struct StackQueue
{
	STDataType * data;
	int top;
	int capacity;
}Stack;

//��ʼ��ջ
void InitStack(Stack* pst);
//����ջ
void DestroyStack(Stack* pst);
//��ջ
void PushStack(Stack* pst, STDataType x);
//��ջ
void PopStack(Stack* pst);
//�ж�ջ�Ƿ�Ϊ��(��Ϊ1����Ϊ0)
int StackEmpty(Stack*pst);
//�ж�ջ�Ĵ�С
int Stacksize(Stack* pst);
//��ȡջ������
STDataType StackTop(Stack*pst);