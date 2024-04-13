#include "stack.h"

void Text1()
{
	Stack pst;
	InitStack(&pst);
	PushStack(&pst, 1);
	PushStack(&pst, 2);
	PushStack(&pst, 3);
	PushStack(&pst, 4);

	PushStack(&pst, 5);
	while (!StackEmpty(&pst))
	{
		printf("%d ", pst.data[pst.top-1]);
		PopStack(&pst);
	}
	DestroyStack(&pst);
	return;
}

int main()
{
	Text1();
	return 0;
}