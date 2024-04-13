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

//初始化栈
void InitStack(Stack* pst);
//销毁栈
void DestroyStack(Stack* pst);
//进栈
void PushStack(Stack* pst, STDataType x);
//出栈
void PopStack(Stack* pst);
//判断栈是否为空(空为1不空为0)
int StackEmpty(Stack*pst);
//判断栈的大小
int Stacksize(Stack* pst);
//获取栈顶数据
STDataType StackTop(Stack*pst);