#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include<stdlib.h>

//函数的申明
void inittotal(struct addressbook* p);
void Add(struct addressbook* p);
void delete(struct addressbook* p);
void print12(struct addressbook* p);
void menu(void);
void search1(struct addressbook* p);
void Modify(struct addressbook* p);
void savecommunicate(struct addressbook* p);

//个人信息有:
//1.名字
//2.年龄
//3.性别
//4.电话号码(12位的电话)
//5.住址
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