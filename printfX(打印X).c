//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//
//void initialization(char* p,int num)//(�Լ�д���㷨1)
//{
//	int i = 0;
//	p[num * sizeof(char)] = '\0';
//	for (i = 0; i < num * sizeof(char) ; i++)
//	{
//		p[i] = ' ';
//	}
//}
//
//void print(char* p,int num)
//{
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		p[i] = '*';
//		p[num * sizeof(char) - 1 - i] = '*';
//		printf("%s\n",p);
//		initialization(p, num);
//	}
//}
//
//int main()
//{
//	int num = 6;
//	printf("������Ҫ��ӡ��x������");
//	scanf("%d", &num);
//	char* p = (char*)malloc(num*sizeof(char)+1);
//	if (p == NULL)
//	{
//		return 1;
//	}
//	initialization(p,num);
//	print(p,num);
//	return 0;
//}

//int main()(TM����bug!��֪����ô�޸��㷨2)
//{
//	int n = 0;
//	int i = 0;
//	int j = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			if (i == j)
//			{
//				printf("*");
//			}
//			else if (i + j == n - 1)
//			{
//				printf("*");
//			}
//			else
//			{
//				printf(" ");
//			}
//		}
//		printf('\n');
//	}
//	return 0;
//}