#include "communicate.h"

void menu()
{
	printf("****************************************\n");
	printf("*****1.add     2.delete    3.modify*****\n");
	printf("*****4.search  5.sort      6.print *****\n");
	printf("************** 7.exit ******************\n");
	printf("****************************************\n");
}

static int findname(struct addressbook*p)
{
	int i = 0;
	char input[20] = { 0 };
	scanf("%s", &input);
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(input, p->total[i].name)==0)
		{
			return i;
		}
	}
	return -1;
}

void inittotal(struct addressbook* p)
{
	
	p->sz = 0;
	p->capacity = 3;
	struct peoinfo* ptr1 = (struct peoinfo*)malloc(3*sizeof(struct peoinfo));
	if (ptr1 == NULL)
	{
		printf("初始化失败\n");
		return;
	}
	p->total = ptr1;
	FILE* ptr = fopen("date.dat", "r");
	if (ptr != NULL)
	{
		int ret = 0;
		while (1)
		{
			if (p->sz == p->capacity)
			{
				p->capacity = p->capacity + 2;
				struct peoinfo* ptr = realloc(p->total, p->capacity * sizeof(struct peoinfo));
				if (ptr == NULL)
				{
					printf("初始化失败:没有多余的内存.\n");
					return;
				}
				p->total = ptr;
			}
			ret = fread(p->total + p->sz, sizeof(struct peoinfo), 1, ptr);
			if (ret <= 0)
			{
				break;
			}
			p->sz++;
		}
	}
	
	//memset(p->total, 0, sizeof(p->total));
}

void Add(struct addressbook* p)
{
	if (p->sz == p->capacity)
	{
		p->capacity= p->capacity +2;
		struct peoinfo* ptr = realloc(p->total,p->capacity*sizeof(struct peoinfo));
		if (ptr == NULL)
		{
			printf("增容量失败\n");
			return;
		}
		p->total = ptr;
		printf("增容成功\n");
	}
	int count = p->sz;
	printf("请输入名字:\n");
	scanf("%s", p->total[count].name);
	printf("请输入年龄(数字):\n");
	scanf("%d", &(p->total[count].age));
	printf("请输入性别:\n");
	scanf("%s", p->total[count].sex);
	printf("请输入电话:\n");
	scanf("%s", p->total[count].tele);
	printf("请输入地址:\n");
	scanf("%s", p->total[count].address);
	p->sz++;
	printf("添加成功\n");
}

void print12(struct addressbook* p)
{
	if (p->sz == 0)
	{
		printf("没有项目可以打印\n");
		return;
	}
	int i = 0;
	printf("%-20s %-5s %-5s %-20s %-30s\n", "姓名", "年龄","性别","电话","地址");
	for (i = 0; i < p->sz; i++)
	{
		printf("%-20s %-5d %-5s %-20s %-30s\n", p->total[i].name, p->total[i].age, p->total[i].sex, p->total[i].tele, p->total[i].address);
	}
}

void delete(struct addressbook* p)
{
	int i = 0;
	if (p->sz == 0)
	{
		printf("通讯录为空,无法进行删除\n");
		return;
	}
	printf("请输入要删除的名字:\n");
	int pos = findname(p);
	if (pos == -1)
	{
		printf("找不到你要删除的人\n");
		return;
	}
	for (i = pos; i<p->sz-1; i++)
	{
		p->total[i] = p->total[i + 1];
	}
	p->sz--;
	printf("删除成功\n");
}

void search1(struct addressbook*p)
{
	printf("请输入要查找人的名字:\n");
	int ret = findname(p);
	if (ret == -1)
	{
		printf("查无此人\n");
		return;
	}
	printf("%-20s %-5s %-5s %-20s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-20s %-5d %-5s %-20s %-30s\n", p->total[ret].name, p->total[ret].age, p->total[ret].sex, p->total[ret].tele, p->total[ret].address);
	return;
}

void Modify(struct addressbook*p)
{
	printf("请输入要修改的人的名字\n");
	int ret = findname(p);
	if (ret == -1)
	{
		printf("查无此人无法进行修改\n");
		return;
	}
	printf("请输入名字:\n");
	scanf("%s", p->total[ret].name);
	printf("请输入年龄:\n");
	scanf("%d", &(p->total[ret].age));
	printf("请输入性别:\n");
	scanf("%s", p->total[ret].sex);
	printf("请输入电话:\n");
	scanf("%s", p->total[ret].tele);
	printf("请输入地址:\n");
	scanf("%s", p->total[ret].address);
	printf("修改成功\n");
	printf("%-20s %-5s %-5s %-20s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-20s %-5d %-5s %-20s %-30s\n", p->total[ret].name, p->total[ret].age, p->total[ret].sex, p->total[ret].tele, p->total[ret].address);
	return;
}

void savecommunicate(struct addressbook*p)
{
	int i = 0;
	FILE* ptr=fopen("date.dat","w");
	if (ptr == NULL)
	{
		printf("出现错误:保存失败.\n");
	}
	for (i = 0; i < p->sz;i++)
	{
		fwrite(p->total + i,sizeof(struct peoinfo),1,ptr);
	}
	printf("保存成功:保持在date.dat文件中\n");
	fclose(ptr);
	return;
}