#include<stdio.h>
#include<string.h>
#include <conio.h>//������ͨ������̨���� �������� ����������ĺ�������getch������
#include"test.h"
void ReaderMainMenu()//���˵�
{
	system("cls");

	printf("**************************************************");

	printf("\n\n 1.ͼ��ϵͳ\n\n");

	printf("\n\n 2.����ϵͳ\n\n");

	printf("\n\n 3.�˳�ϵͳ\n\n");

	printf("\n\n �밴��ѡ�񣬻س�ȷ��\n");

	printf("*************************************************\n");

	return;
}


void BookMenu() //ͼ�����Ϣ�˵�
{
	system("cls");

	printf("****************************************************");


	printf("\n 1.��ѯͼ��\n\n");

	printf("\n 2.������\n\n");

	printf("\n 3.ͼ������\n\n");

	printf("\n 4.ģ����ѯ\n\n");

	printf("\n 5.������һ��\n\n");

	printf("\n �밴��ѡ�񣬻س�ȷ��\n");

	printf("***************************************************\n");

	return;

}

void AdministratorBookMenu() //ͼ�����Ϣ�˵�
{
	system("cls");

	printf("****************************************************");

	printf("\n 1.����ͼ��\n\n");
	printf("\n 2.ɾ��ͼ��\n\n");

	printf("\n 3.��ѯͼ��\n\n");

	printf("\n 4.������\n\n");

	
	printf("\n 5.������һ��\n\n");

	printf("\n �밴��ѡ�񣬻س�ȷ��\n");

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
	printf("��������밴�������������");
	int k = getch();
	system("cls");
	AdministratorBookFunction();
	return;

}
void BorrowMenu()//��ʾ����˵�
{
	system("cls");
	printf("*****************************************************");
	printf("\n\n1.����Ǽ�\n\n");
	printf("\n\n2.����Ǽ�\n\n");
	printf("\n\n3.��������鿴\n\n");
	printf("\n\n4.������һ��\n\n");
	printf("\n\n�밴��ѡ�񣬻س�ȷ��\n");
	printf("****************************************************");
}
void WelcomeMenu()
{
	printf("*****************************************************");
	printf("\n\n\t\t��ӭʹ��ͼ�����ϵͳ\n");
	printf("\n\n\t\t ���ߵ�½�����롰1��\n");
	printf("\n\n\t\t����Ա��½�����롰2��\n");
	printf("\n\n\t\t �˳�ϵͳ�����롰3��\n");
	printf("\n\n\t\t�밴��ѡ�񣬻س�ȷ��\n");
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

				printf("��������밴�������������");
				getch();
				WelcomeFunction();
			}
			}
		}
}
		printf("��������밴�������������");
		int k=getch();
		system("cls");
		WelcomeFunction();
		return;
	
}

void AdministratorMenu()
{
	printf("*****************************************************");
	printf("\t\t\n\n��ѡ���ܣ�\n\n");
	printf("\t\t\n\n1.�������\n\n");
	printf("\t\t\n\n2.����ͼ��\n\n");
	printf("\t\t\n\n3.������һ��\n\n");
	printf("\t\t\n\n4.�ļ�����\n\n");
	printf("\t\t\n\n�밴��ѡ�񣬻س�ȷ��\n\n");

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
				printf("��������밴���������������");
				getch();
				AdministratorFunction();

			}
			}
		}

	}
	printf("��������밴�������������");
	int k = getch();
	system("cls");
	AdministratorFunction();
	return;
}

void ReaderManagerMenu()
{
	system("cls");

	printf("****************************************************");

	printf("\n 1.���Ӷ�����Ϣ\n\n");

	printf("\n 2.�޸Ķ�����Ϣ\n\n");

	printf("\n 3.ɾ��������Ϣ\n\n");

	printf("\n 4.������Ϣ���\n\n");

	printf("\n 5.������Ϣ��ѯ\n\n");

	printf("\n 6.������һ��\n\n");

	printf("\n �밴��ѡ�񣬻س�ȷ��\n");

	printf("***************************************************\n");


}

