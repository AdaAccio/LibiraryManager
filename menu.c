#include<stdio.h>
#include<string.h>
#include <conio.h>//定义了通过控制台进行 数据输入 和数据输出的函数，如getch函数。
#include"test.h"
void ReaderMainMenu()//主菜单
{
	system("cls");

	printf("**************************************************");

	printf("\n\n 1.图书系统\n\n");

	printf("\n\n 2.借阅系统\n\n");

	printf("\n\n 3.退出系统\n\n");

	printf("\n\n 请按键选择，回车确定\n");

	printf("*************************************************\n");

	return;
}


void BookMenu() //图书馆信息菜单
{
	system("cls");

	printf("****************************************************");


	printf("\n 1.查询图书\n\n");

	printf("\n 2.库存浏览\n\n");

	printf("\n 3.图书排序\n\n");

	printf("\n 4.模糊查询\n\n");

	printf("\n 5.返回上一层\n\n");

	printf("\n 请按键选择，回车确定\n");

	printf("***************************************************\n");

	return;

}

void AdministratorBookMenu() //图书馆信息菜单
{
	system("cls");

	printf("****************************************************");

	printf("\n 1.增加图书\n\n");
	printf("\n 2.删除图书\n\n");

	printf("\n 3.查询图书\n\n");

	printf("\n 4.库存浏览\n\n");

	
	printf("\n 5.返回上一层\n\n");

	printf("\n 请按键选择，回车确定\n");

	printf("***************************************************\n");
	return;

}


void AdministratorBookFunction()
{

	system("cls");
	AdministratorBookMenu();
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
			AdministratorBookFunction();
		}
		else
		{
			switch (index[0])
			{
			case'1':
				adds();
				break;
			case'2':
				removes();
				break;
			case'3':
				AdministratorBookSearch();
				break;
			case'4':
				AdministratorVisitBook();
				break;
			case'5':
				AdministratorFunction();
				break;
			default:
				AdministratorBookFunction();
			}
		}
	}
	printf("输入错误，请按任意键重新输入");
	int k = getch();
	system("cls");
	AdministratorBookFunction();
	return;

}
void BorrowMenu()//显示借书菜单
{
	system("cls");
	printf("*****************************************************");
	printf("\n\n1.借书登记\n\n");
	printf("\n\n2.还书登记\n\n");
	printf("\n\n3.借阅情况查看\n\n");
	printf("\n\n4.返回上一层\n\n");
	printf("\n\n请按键选择，回车确定\n");
	printf("****************************************************");
}
void WelcomeMenu()
{
	printf("*****************************************************");
	printf("\n\n\t\t欢迎使用图书管理系统\n");
	printf("\n\n\t\t 读者登陆，输入“1”\n");
	printf("\n\n\t\t管理员登陆，输入“2”\n");
	printf("\n\n\t\t 退出系统，输入“3”\n");
	printf("\n\n\t\t请按键选择，回车确定\n");
	printf("*****************************************************");
}
void WelcomeFunction()
{

	system("cls");
	WelcomeMenu();
	char index[200];
	while(1)
	{
		gets(index);
		int len = strlen(index);
		if (len > 1)
		{
			break;
		}
		else
		{
			switch (index[0])
			{
			case('1'):
			{
				ReaderLandMain();
				break;
			}
			case('2'):
			{
				AdministratorLand();
				break;
			}
			case('3'):
			{
				exit(0);
				break;
			}
			
			default:
			{

				printf("输入错误，请按任意键重新输入");
				getch();
				WelcomeFunction();
			}
			}
		}
}
		printf("输入错误，请按任意键重新输入");
		int k=getch();
		system("cls");
		WelcomeFunction();
		return;
	
}

void AdministratorMenu()
{
	printf("*****************************************************");
	printf("\t\t\n\n请选择功能：\n\n");
	printf("\t\t\n\n1.管理读者\n\n");
	printf("\t\t\n\n2.管理图书\n\n");
	printf("\t\t\n\n3.返回上一层\n\n");
	printf("\t\t\n\n4.文件备份\n\n");
	printf("\t\t\n\n请按键选择，回车确定\n\n");

	printf("*****************************************************");
}
void AdministratorFunction()
{
	system("cls");
	AdministratorMenu();
	char index[200] = { 0 };
	while (scanf("%s", index) == 1)
	{
		int len = strlen(index);
		if (len > 1)
		{
			break;
		}
		else if (len == 0)
		{
			AdministratorFunction();
		}
		else
		{
			switch (index[0])
			{
			case('1'):
			{
				ReaderFunction();
				break;
			}
			case('2'):
			{
				AdministratorBookFunction();
				break;
			}
			case('3'):
			{
				WelcomeFunction();
				break;
			}
			case('4'):
			{
				FileCopy();
				break;
			}
			default:
			{
				printf("输入错误，请按任意键后重新输入");
				getch();
				AdministratorFunction();

			}
			}
		}

	}
	printf("输入错误，请按任意键重新输入");
	int k = getch();
	system("cls");
	AdministratorFunction();
	return;
}

void ReaderManagerMenu()
{
	system("cls");

	printf("****************************************************");

	printf("\n 1.增加读者信息\n\n");

	printf("\n 2.修改读者信息\n\n");

	printf("\n 3.删除读者信息\n\n");

	printf("\n 4.借阅信息浏览\n\n");

	printf("\n 5.读者信息查询\n\n");

	printf("\n 6.返回上一层\n\n");

	printf("\n 请按键选择，回车确定\n");

	printf("***************************************************\n");


}

