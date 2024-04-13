#include "stack.h"

void InitStack(Stack* pst)
{
	pst->data = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (pst == NULL)
	{
		printf("空间不足\n");
		exit(-1);
	}
	pst->capacity = 4;
	pst->top = 0;
	return;
}

void PushStack(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		pst->capacity *= 2;
		pst->data = (STDataType*)realloc(pst->data,sizeof(STDataType) *(pst-> capacity));
		if (pst->data == NULL)
		{
			printf("空间不足\n");
			exit(-1);
		}
	}
	pst->data[pst->top] = x;
	pst->top += 1;
	return;
}

void PopStack(Stack* pst)
{
	assert(pst);
	if (pst->top <= 0)
	{
		printf("无内容可以出栈\n");
		return;
	}
	pst->top -= 1;
	return;
}

void DestroyStack(Stack* pst)
{
	assert(pst);
	free(pst->data);
	pst->data = NULL;
	pst->top = 0;
	pst->capacity = 0;
	return;
}

int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top==0 ? 1 : 0;
}

int Stacksize(Stack* pst)
{
	assert(pst);
	return pst->top;
}

STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->top != 0);
	return pst->data[pst->top-1];
}