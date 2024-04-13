#include "queue.h"

void Text1()
{
	Queue* qp = NULL;
	QueueInit(&qp);
	QueuePush(qp, 1);
	QueuePush(qp, 2);
	QueuePush(qp, 3);
	QueuePush(qp, 4);
	QueuePush(qp, 5);
	QueuePush(qp, 6);
	QueuePush(qp, 7);
	int n = QueueFront(qp);
	int m = QueueBack(qp);
	printf("%d \n", n);
	printf("%d \n", m);
	while (!QueueEmpty(qp))
	{
		printf("%d ", qp->head->x);
		QueuePop(qp);
	}
	return;
}


int main()
{
	Text1();
	return;
}