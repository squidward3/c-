#include "sequencelist.h"

void slinit(SL* ps)
{
	assert(ps);
	ps->arry = (sltype)malloc(sizeof(sltype) * initcount);
	if (ps->arry == NULL)
	{
		perror("memory");
		exit(-1);
	}
	ps->capacity = initcount;
	ps->size = 0;
}

void checkslmemory( SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;
		ps->arry = (sltype)realloc(ps->arry, sizeof(sltype) * ps->capacity);
		if (ps->arry == NULL)
		{
			perror("memory");
			exit(-1);
		}
	}
}

void printsl( SL* ps)
{
	assert(ps);
	int i = 0;
	for(i=0;i<ps->size;i++)
	{
		printf("%d ", ps->arry[i]);
	}
	printf("\n");
}

void slpushback( SL* ps, sltype x)
{
	assert(ps);
	checkslmemory(ps);
 	ps->arry[ps->size] = x;
	ps->size++;
}

void slpopback( SL* ps)
{   
	assert(ps);
	if (ps->size > 0)
	{
		ps->size--;
	}
	else
	{
		printf("没有元素可以删除\n");
	}
}

void slpushfront(SL* ps, const sltype x)
{
	assert(ps);
	int end = ps->size;
	checkslmemory(ps);  
	ps->size++;
	while (end--)
	{
		ps->arry[end + 1] = ps->arry[end];
	}
	ps->arry[0] = x;
}

void slpopfront(SL* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("没有元素可以删除\n");
	}
	if (ps->size > 0)
	{
		int start = 0;
		for (start = 0; start < ps->size - 1; start++)
		{
			ps->arry[start] = ps->arry[start + 1];
		}
		ps->size--;
	}
}

void slinsert(SL*  ps,const unsigned int pos,const sltype x)
{
	assert(ps);
	if (pos >= ps->size)
	{
		printf("都比size大了还怎么插?\n");
		return;
	}
	else if (pos == 0 )
	{
		printf("0?你想插在第0个元素的后面?\n");
		return;
	}
	int end = ps->size - 1;
	checkslmemory(ps);
	ps->size++;
	while ( !((end--)==pos-1))
	{
		ps->arry[end + 1] = ps->arry[end];
	}
	ps->arry[pos] = x;
}

void slerase(SL* ps,unsigned int pos)
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("没有元素可以删除\n");
	}
	if (ps->size > 0)
	{
		int start = pos-1;
		for (start = pos - 1; start < ps->size - 1; start++)
		{
			ps->arry[start] = ps->arry[start + 1];
		}
		ps->size--;
	}
}

void slfind(SL* ps)
{
	int i = 0;
	sltype x = 0;
	printf("你要找的元素\n");
	scanf("%d", &x);
	for (i = 0; i < ps->size; i++)
	{
		if (ps->arry[i] == x)
		{
			printf("找到了: %d",i+1);
			return ;
		}
	}
	printf("没有找到\n");
}

void slsort(SL* ps)
{
	int i = 0;
	int j = 0;
	sltype tmp = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		for (j = 0; j < ps->size - i-1; j++)
		{
			if (ps->arry[j] > ps->arry[j + 1])
			{
				tmp = ps->arry[j];
				ps->arry[j] = ps->arry[j + 1];
				ps->arry[j + 1] = tmp;
			}
		}
	}
}

void sldestroy(SL* ps)
{
	assert(ps);
	free(ps);
	ps = NULL;
}