#include <stdio.h>
#include <stdlib.h>//其中包含system函数
#include <conio.h>//定义了通过控制台进行 数据输入 和数据输出的函数，如getch函数。
#include <string.h>//定义字符数组
#include <math.h>
#define LEN sizeof(struct book)//有关图书信息的结构体
#define LEN1 sizeof(struct reader)//有关读者信息的结构体
#define LEN2 sizeof(struct land)//有关登录系统的结构体
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
			switch (index[0])//功能函数
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
				printf("输入错误，请按任意键重新输入");
				getch();
				ReaderMainFunction();
			}

		}
	}
	printf("输入错误，请按任意键重新输入");
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
	printf("输入错误，请按任意键重新输入");
	int k = getch();
	system("cls");
	BookManageFunction();
	return;

}

int main()
{
	system("color 1F");//蓝底白字
	WelcomeFunction();
	return 0;
}

