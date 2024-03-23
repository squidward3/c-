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
		printf("��ʼ��ʧ��\n");
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
					printf("��ʼ��ʧ��:û�ж�����ڴ�.\n");
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
			printf("������ʧ��\n");
			return;
		}
		p->total = ptr;
		printf("���ݳɹ�\n");
	}
	int count = p->sz;
	printf("����������:\n");
	scanf("%s", p->total[count].name);
	printf("����������(����):\n");
	scanf("%d", &(p->total[count].age));
	printf("�������Ա�:\n");
	scanf("%s", p->total[count].sex);
	printf("������绰:\n");
	scanf("%s", p->total[count].tele);
	printf("�������ַ:\n");
	scanf("%s", p->total[count].address);
	p->sz++;
	printf("��ӳɹ�\n");
}

void print12(struct addressbook* p)
{
	if (p->sz == 0)
	{
		printf("û����Ŀ���Դ�ӡ\n");
		return;
	}
	int i = 0;
	printf("%-20s %-5s %-5s %-20s %-30s\n", "����", "����","�Ա�","�绰","��ַ");
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
		printf("ͨѶ¼Ϊ��,�޷�����ɾ��\n");
		return;
	}
	printf("������Ҫɾ��������:\n");
	int pos = findname(p);
	if (pos == -1)
	{
		printf("�Ҳ�����Ҫɾ������\n");
		return;
	}
	for (i = pos; i<p->sz-1; i++)
	{
		p->total[i] = p->total[i + 1];
	}
	p->sz--;
	printf("ɾ���ɹ�\n");
}

void search1(struct addressbook*p)
{
	printf("������Ҫ�����˵�����:\n");
	int ret = findname(p);
	if (ret == -1)
	{
		printf("���޴���\n");
		return;
	}
	printf("%-20s %-5s %-5s %-20s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s %-5d %-5s %-20s %-30s\n", p->total[ret].name, p->total[ret].age, p->total[ret].sex, p->total[ret].tele, p->total[ret].address);
	return;
}

void Modify(struct addressbook*p)
{
	printf("������Ҫ�޸ĵ��˵�����\n");
	int ret = findname(p);
	if (ret == -1)
	{
		printf("���޴����޷������޸�\n");
		return;
	}
	printf("����������:\n");
	scanf("%s", p->total[ret].name);
	printf("����������:\n");
	scanf("%d", &(p->total[ret].age));
	printf("�������Ա�:\n");
	scanf("%s", p->total[ret].sex);
	printf("������绰:\n");
	scanf("%s", p->total[ret].tele);
	printf("�������ַ:\n");
	scanf("%s", p->total[ret].address);
	printf("�޸ĳɹ�\n");
	printf("%-20s %-5s %-5s %-20s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s %-5d %-5s %-20s %-30s\n", p->total[ret].name, p->total[ret].age, p->total[ret].sex, p->total[ret].tele, p->total[ret].address);
	return;
}

void savecommunicate(struct addressbook*p)
{
	int i = 0;
	FILE* ptr=fopen("date.dat","w");
	if (ptr == NULL)
	{
		printf("���ִ���:����ʧ��.\n");
	}
	for (i = 0; i < p->sz;i++)
	{
		fwrite(p->total + i,sizeof(struct peoinfo),1,ptr);
	}
	printf("����ɹ�:������date.dat�ļ���\n");
	fclose(ptr);
	return;
}