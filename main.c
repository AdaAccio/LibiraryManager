#include <stdio.h>
#include <stdlib.h>//���а���system����
#include <conio.h>//������ͨ������̨���� �������� ����������ĺ�������getch������
#include <string.h>//�����ַ�����
#include <math.h>
#define LEN sizeof(struct book)//�й�ͼ����Ϣ�Ľṹ��
#define LEN1 sizeof(struct reader)//�йض�����Ϣ�Ľṹ��
#define LEN2 sizeof(struct land)//�йص�¼ϵͳ�Ľṹ��
#pragma warning(disable:4996);
extern int ReaderID = 0;
#include <assert.h>

#include "test.h"
void ReaderMainFunction()
{

	system("cls");
	ReaderMainMenu();
	char index[200] = { 0 };
	while (1)
	{
		gets(index);
		int len = strlen(index);
		if (len > 1)
		{
			break;
		}
		else if (len == 0)
		{
			ReaderMainFunction();
		}
		else
		{
			int n = ReaderID;
			switch (index[0])//���ܺ���
			{
			case'1':
				BookManageFunction();
				break;
			case'2':
				borrow_message();
				break;
			case'3':
				system("cls");
				getch();
				WelcomeFunction();
				break;
			default:
				printf("��������밴�������������");
				getch();
				ReaderMainFunction();
			}

		}
	}
	printf("��������밴�������������");
	int k = getch();
	system("cls");
	ReaderMainFunction();
	return;

}



void BookManageFunction()
{

	system("cls");
	BookMenu();
	char index[200];
	while (1)
	{
		gets(index);
		int len = strlen(index);
		if (len > 1)
		{
			break;
		}
		else if (len == 0)
		{
			BookManageFunction();
		}
		else
		{
			switch (index[0])
			{
			case'1':
				search();
				break;
			case'2':
				visit();
				break;
			case'3':
				sort();
				break;
			case'4':
				vague();
				break;
			case'5':
				ReaderMainFunction();
				break;
			default:
				BookManageFunction();
			}
		}
	}
	printf("��������밴�������������");
	int k = getch();
	system("cls");
	BookManageFunction();
	return;

}

int main()
{
	system("color 1F");//���װ���
	WelcomeFunction();
	return 0;
}

