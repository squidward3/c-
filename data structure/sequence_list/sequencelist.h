#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define initcount 4

typedef int sltype;

typedef struct sequencelist
{
	sltype* arry;
	int size;
	int capacity;
}SL;

//检查是否要添加空间
void checkslmemory(SL* ps);
//初始化
void slinit(SL*ps);
//打印顺序表
void printsl(SL* ps);
//尾插
void slpushback(SL* ps, sltype x);
//尾删
void slpopback(SL*ps);
//头插
void slpushfront(SL* ps, sltype x);
//头删
void slpopfront(SL* ps);
//中间插入(向后插)
void slinsert(SL* ps,const unsigned int pos,const sltype x);
//中间删除 
void slerase(SL* ps, unsigned int pos);
//查找
void slfind(SL* ps);
//排序
void slsort(SL* ps);
//销毁顺序表
void sldestroy(SL* ps);
