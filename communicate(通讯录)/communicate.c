#include "communicate.h"

//ͨѶ¼�Ĺ���
//1.���
//2.ɾ��
//3.�޸�
//4.����
//5.����
//6.��ӡ
//7.�˳�
enum function
{
	add = 1,
	dele = 2,
	modify = 3,
	search = 4,
	sort = 5,
	print = 6,
	exit1 = 7,
};

int main()
{
	int input = 0;
	inittotal(&a);
	do {
		menu ();
		printf("������:\n");
		scanf("%d",&input);
		system("cls");
		switch (input)
		{
		case add:
			system("cls");
			Add(&a);
			break;
		case dele:
			system("cls");
			delete(&a);
			break;
		case modify:
			Modify(&a);
			break;
		case search:
			system("cls");
			search1(&a);
			break;
		case sort:
			break;
		case print:
			system("cls");
			print12(&a);
			break;
		case exit1:
			savecommunicate(&a);
			return;
			break;
		default:
			printf("��������Ч����\n");
			break;
		}

	} while (input);
	return 0;
}