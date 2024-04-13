#include "list.h"

void text()
{
	node* phead = NULL;
	list_init(&phead);
	listpushfront(phead, 1);
	listpushfront(phead, 2);
	listpushfront(phead, 3);
	listpushfront(phead, 4);
	listpushfront(phead, 5);

	listprint(phead);
	listinsert(phead, 90, 3);
	listerase(phead, 5);



	listprint(phead);

	return 0;
}

int main()
{
	text();
	return 0;
}