#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include<stdlib.h>

//����������
void inittotal(struct addressbook* p);
void Add(struct addressbook* p);
void delete(struct addressbook* p);
void print12(struct addressbook* p);
void menu(void);
void search1(struct addressbook* p);
void Modify(struct addressbook* p);
void savecommunicate(struct addressbook* p);

//������Ϣ��:
//1.����
//2.����
//3.�Ա�
//4.�绰����(12λ�ĵ绰)
//5.סַ
struct peoinfo
{
	char name[20];
	int age;
	char sex[10];
	char tele[20];
	char address[30];
};

struct addressbook 
{
	struct peoinfo* total;
	int sz ;
	int capacity;
}a;