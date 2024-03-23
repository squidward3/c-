#include "communicate.h"

//通讯录的功能
//1.添加
//2.删除
//3.修改
//4.查找
//5.整理
//6.打印
//7.退出
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
		printf("请输入:\n");
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
			printf("请输入有效数字\n");
			break;
		}

	} while (input);
	return 0;
}