#include <stdio.h>
#include <stdlib.h>//其中包含system函数
#include <conio.h>//定义了通过控制台进行 数据输入 和数据输出的函数，如getch函数。
#include <string.h>//定义字符数组
#include <math.h>
#include <assert.h>
extern int ReaderID;
#define LEN sizeof(struct book)//有关图书信息的结构体
#include "test.h"

void ReaderFunction()
{

	system("cls");
	ReaderManagerMenu();
	char index[200];
	while (scanf("%s", index) == 1)
	{
		int len = strlen(index);
		if (len > 1)
		{
			break;
		}
		else if (len == 0)
		{
			ReaderFunction();
		}
		else
		{
			switch (index[0])
			{
			case('1'):
			{
				AddReader();
				break;
			}
			case('2'):
			{
				ReaderProfileChange();
				break;
			}
			case('3'):
			{
				ReaderDelete();
				break;
			}
			case('4'):
			{
				inquire();
				break;
			}
			case('5'):
			{
				ReaderSearch();
				break;
			}
			case('6'):
			{
				AdministratorFunction();
				break;
			}
			default:
			{

				printf("输入错误，请按任意键重新输入");
				getch();
				AdministratorLand();
			}
			}
		}
	}
	printf("输入错误，请按任意键重新输入");
	int k = getch();
	system("cls");
	AdministratorLand();
	return;

}
int AdministratorCount()
{
	FILE* fp;
	int ID = 0, n;
	char code[100] = { '\0' };
	fp = fopen("Administrator.txt", "r");//打开文件
	for (n = 0; !feof(fp); n++)//逐个读文件
		fscanf(fp, "%d %s", &ID, code);
	n--;
	fclose(fp);//关闭文件
	return n;//返回个数
}
int matchAdministrator(int m, char a[100])
{
	FILE* fp;
	int n = 0, i = 0;
	int ID_card;
	char password[100];

	if ((fp = fopen("Administrator.txt", "r")) == NULL)//不存在管理员文件
	{
		system("cls");
		printf("\n 还未存在用户!请新建账户");
		getch();
		system("cls");
		AdministratorLand();

	}


	for (; !feof(fp);)
	{
		fscanf(fp, "%d%s", &ID_card, password);
		if (m == ID_card)
		{
			if (strcmp(a, password) == 0)
				return 1;
			else
			{
				return -1;
			}
		}
	}
	return 0;
}
void AdministratorLandMenu()
{
	system("cls");
	printf("\n\n\t    欢迎使用管理员登录系统\n\n");
	printf("**********************************************");
	printf("\n\n\t\t1.登录管理员系统\n\n");
	printf("\n\n\t\t2.修改密码\n\n");
	printf("\n\n\t\t3.退出系统\n\n");
	printf("\n\n\t    请按键选择，回车确定\n");
	printf("**********************************************");
}
void AdministratorAlter(int z, char m[100])//修改函数
{
	FILE* fp;
	int ID_card1, n = 0, j, k;
	char mima1[100];
	struct administrator* head = NULL, * p = NULL, * p1 = NULL, * p2 = NULL;

	fp = fopen("Administrator.txt", "r");
	j = AdministratorCount();
	for (k = 0; k <= j; k++)
	{
		fscanf(fp, "%d %s", &ID_card1, mima1);
		if (z != ID_card1)//比较名字，将不同名字的信息复制到链表
		{
			n++;//相同返回值为0不执行if语句继续循环，不同则执行直到将所有不同的书名建立成链表
			if (n == 1)//建立链表
			{
				p1 = p2 = (struct administrator*)malloc(LEN3);
				head = p1;
			}
			else
			{
				p2->next = p1;
				p2 = p1;
				p1 = (struct administrator*)malloc(LEN3);//新建链表
			}
			p1->ID = ID_card1;
			strcpy(p1->password, mima1);//复制账号密码
		}
	}
	if (n == 0)
	{
		head = NULL;
	}
	else//建立链表的最后剩余一个储存空间，所以封底
	{
		p2->next = p1;
		p1->next = NULL;
		fclose(fp);
	}
	fp = fopen("Administrator.txt", "w");//清空文件，只写打开，然后关闭
	fclose(fp);
	fp = fopen("Administrator.txt", "a");//追加文件
	p = head;
	for (; p != NULL;)//把链表内容覆盖到文件
	{
		fprintf(fp, "%d %s%\n", p->ID, p->password);
		p = p->next;
	}
	fprintf(fp, "%d %s\n", z, m);
	fclose(fp);
	system("cls");

}
void AdministratorAlterCode()
{
	FILE* fp;
	int ID = 0, k = 0, count = 0, m = 0, n = 0;
	int inputID, hit;
	char inputPassword[100] = { '\0' }, password1[100] = { '\0' }, password0[100] = { 0 };
	char  password[100] = { '\0' };
	char i;

	if ((fp = fopen("Administrator.txt", "r")) == NULL)//打开文件
	{
		system("cls");
		printf("\n记录文件不存在!按任意键返回");
		getch();
		system("cls");
		AdministratorLand();
	}
	system("cls");
	printf("请输入你的帐号和旧密码：\n");
	scanf("%d %s", &inputID, inputPassword);
	m = AdministratorCount();
	for (n = 0; n <= m; n++)
	{
		fscanf(fp, "%d %s", &ID, password);
		if (ID == inputID)
		{
			if (!strcmp(password, inputPassword))
			{
				printf("请输入新的密码");
				scanf("%s", password0);
				printf("再次输入密码:\n");
				scanf("%s", password1);
				if (strcmp(password0, password1) == 0)
				{
					AdministratorAlter(inputID, password0);
					getch();
					AdministratorLand();
					system("cls");
				}
				else
				{
					printf("两次输入密码不一致,按任意键退出");
					hit = getch();
					system("cls");
					AdministratorLand();

				}
			}
			else
			{
				printf("旧密码错误，按任意键返回！");
				getch();
				system("cls");
				AdministratorLand();

			}

		}
	}
	printf("不存在此账号，按任意键返回");
	fclose(fp);//修改结束
	getch();
	system("cls");
	AdministratorLand();
}
void AdministratorLandMain()
{
	int ID_card;
	char password[100];
	int i = 2, j, k, n;
	char hit = 0;
	system("cls");
	do
	{
		printf("\n请输入账号:\n");
		scanf("%d", &ID_card);
		printf("确认输入请安回车，重新输入请按ECS");
		hit = getch();//暂停程序当i接收后继续下一条指令
		for (; hit != 13 && hit != 27;)//保证只能是CR和ESC才能退出循环,输入其他字符无用，暂停程序，按'CR'继续。
		{
			hit = getch();
		}
	} while (hit == 27);
	printf("\n请输入密码:\n");
	scanf("%s", password);
	i = matchAdministrator(ID_card, password);
	if (i == 1)
	{
		printf("登陆成功!按任意键继续");
		getch();
		system("cls");
		AdministratorFunction();
	}
	else
	{
		if (i == -1)
		{
			printf("密码错误!");
			getch();
			AdministratorLand();
		}
		if (i == 0)
			printf("不存在此用户");
		getch();
		system("cls");
		AdministratorLand();
	}

}

void AdministratorLand()
{

	system("cls");
	AdministratorLandMenu();
	char index[200];
	while (scanf("%s", index) == 1)
	{
		int len = strlen(index);
		if (len > 1)
		{
			break;
		}
		else if (len == 0)
		{
			AdministratorLand();
		}
		else
		{
			switch (index[0])
			{
			case'1':
				AdministratorLandMain();
				break;
			case'2':
				AdministratorAlterCode();
				break;
			case'3':
				system("cls");
				WelcomeFunction();
				break;
			default:
			{

				printf("输入错误，请按任意键重新输入");
				getch();
				AdministratorLand();
			}
			}
		}
	}
	printf("输入错误，请按任意键重新输入");
	int k = getch();
	system("cls");
	AdministratorLand();
	return;

}
void ReaderProfileChange() {
	system("cls");
	FILE* fp;
	struct reader* p, * head = NULL;
	int inputID, ID, type, flag = 0;
	char name[100], NewName[100];
	int NewType;

	fp = fopen("reader.txt", "r");
	if (fp == NULL) {
		printf("无法打开文件\n");
		return;
	}

	printf("请输入读者ID：\n");
	scanf("%d", &inputID);

	if (feof(fp) != 0) {
		printf("暂无读者信息\n");
	}
	else {
		printf("请输入想要修改的信息：\n1.姓名\n2.读者类型\n");
		int index;
		scanf("%d", &index);

		switch (index) {
		case 1:
			printf("请输入新姓名：\n");
			scanf("%s", NewName);
			//NewType = type;
			break;
		case 2:
			printf("请输入新类型(0-3)：\n");
			scanf("%d", &NewType);
			//strcpy(NewName, name);
			break;
		default:
			printf("输入错误！\n");
			fclose(fp);
			return;
		}

		while (fscanf(fp, "%d %s %d", &ID, name, &type) == 3) {
			p = (struct reader*)malloc(sizeof(struct reader));
			p->ID_card = ID;

			if (inputID == ID) {
				flag++;
				if (index == 1)
				{
					p->type = type;
					strcpy(p->name, NewName);
				}
				else if (index == 2)
				{
					strcpy(p->name, name);
					p->type = NewType;
				}
			}
			else {
				strcpy(p->name, name);
				p->type = type;
			}

			p->prev = NULL;
			p->next = NULL;

			if (head == NULL) {
				head = p;
			}
			else {
				p->prev = head;
				head->next = p;
				head = p;
			}
		}

		if (flag == 0) {
			printf("该账号不存在，请重新输入\n");
		}
		else {
			fclose(fp);
			fp = fopen("reader.txt", "w");
			struct reader* temp = head;
			while (temp != NULL) {
				fprintf(fp, "%d %s %d\n", temp->ID_card, temp->name, temp->type);
				temp = temp->prev;
				free(head);
				head = temp;
			}
		}
		fclose(fp);
	}

	printf("修改成功！\n");
	getch();
	system("cls");
	ReaderFunction();
}
void ReaderSearch()
{
	system("cls");
	FILE* fp;
	fp = fopen("reader.txt", "r");
	int flag = 0;
	printf("请输入你想要查找的账号：\n");
	int inputID;
	scanf("%d", &inputID);
	if (feof(fp) != 0)
	{
		printf("暂无读者信息\n");
	}
	while (feof(fp) == 0)
	{
		int ID, type;
		char name[100] = { 0 };
		fscanf(fp,"%d %s %d", &ID, name, &type);
		if (inputID == ID)
		{
			flag++;
			printf("该读者的信息如下：\n姓名：%s\n类型：", name);
			if (type == 0)
			{
				printf("本科生\n");
				break;
			}
			else if (type == 1)
			{
				printf("研究生\n");
				break;
			}
			else if (type == 2)
			{
				printf("博士生\n");
				break;
			}
			else if (type == 3)
			{
				printf("教职工\n");
				break;
			}
			else
			{
				printf("ERROR");
				break;
			}

		}
	}
	if (flag == 0)
	{
		printf("未查询到该读者");
	}
	printf("按任意键返回上一层");
	getch();
	system("cls");
	ReaderFunction();

}

void AddReader()
{
	system("cls");
	char addPassword[100];
	int addID;
	char filename[1000] = {0};
	printf("请输入添加的读者账号：\n");
	scanf("%d", &addID);
	itoa(addID, filename, 10);

	printf("请输入读者默认密码：\n");
	scanf("%s", addPassword);
	printf("请输入读者姓名：\n");
	char name[100] = { 0 };
	scanf("%s", name);
	//fprintf("%d %s", addID, addPassword);
	printf("请选择读者类型：\n");
	printf("0：本科生\n");
	printf("1：研究生\n");
	printf("2：博士生\n");
	printf("3：教职员工\n");
	int type;
	strcat(filename, ".txt");
	scanf("%d", &type);
	FILE* fp1 = fopen(filename, "r");
	FILE* fp2, * fp3;
	if (fp1 != NULL)
	{
		printf("该读者已存在\n");
	}
	else
	{
		fp1=fopen(filename, "w");
		fclose(fp1);
		fp2 = fopen("reader.txt", "a");
		fprintf(fp2,"\n%d %s %d\n", addID, name, type);
		fclose(fp2);
		fp3 = fopen("land.txt", "a");
		fprintf(fp3,"\n%d %s", addID, addPassword);
		fclose(fp3);
		printf("读者%d录入成功\n", addID);

	}
	getch();
	system("cls");
	ReaderFunction();

}
void ReaderDelete()
{
	system("cls");
	FILE* fp;
	struct reader* p, * head = NULL, * prev = NULL;
	int inputID, ID, type, flag = 0;
	char name[100];

	fp = fopen("reader.txt", "r");
	if (fp == NULL) {
		printf("无法打开文件\n");
		return;
	}

	printf("请输入读者ID：\n");
	scanf("%d", &inputID);

	if (feof(fp) != 0) {
		printf("暂无读者信息\n");
	}
	else {
		while (fscanf(fp, "%d %s %d", &ID, name, &type) == 3) {
			p = (struct reader*)malloc(sizeof(struct reader));
			p->ID_card = ID;
			strcpy(p->name, name);
			p->type = type;
			p->prev = NULL;
			p->next = NULL;

			if (inputID == ID) {
				flag++;
				if (prev == NULL) {
					head = p->next;
					if (head != NULL) {
						head->prev = NULL;
					}
					free(p);
				}
				else {
					prev->next = p->next;
					if (p->next != NULL) {
						p->next->prev = prev;
					}
					free(p);
				}
			}
			else {
				if (head == NULL) {
					head = p;
				}
				else {
					p->prev = head;
					head->next = p;
					head = p;
				}
			}

			prev = p;
		}

		if (flag == 0) {
			printf("未找到匹配的读者ID\n");
		}
		else {
			fclose(fp);
			fp = fopen("reader.txt", "w");
			struct reader* temp = head;
			while (temp != NULL) {
				fprintf(fp, "%d %s %d\n", temp->ID_card, temp->name, temp->type);
				struct reader* current = temp;
				temp = temp->prev;
				free(current);
			}
			printf("删除成功！\n");
		}
		fclose(fp);
	}
	getch();
	system("cls");
	ReaderFunction();
}
void AdministratorBookSearch() {
	system("cls");
	FILE* fp;
	char query[100];
	int found = 0;
	struct BookNode* head = NULL;
	struct BookNode* current = NULL;
	current = (struct BookNode*)malloc(sizeof(struct BookNode));

	// 打开图书馆文件
	fp = fopen("library.txt", "r");
	if (fp == NULL) {
		printf("错误：找不到图书馆文件！\n");
		return;
	}

	// 读取用户输入的搜索查询
	printf("请输入书号、书名、作者或类别进行搜索：");
	scanf("%s", query);

	// 读取文件中的图书信息并构建双向链表
	while (fscanf(fp, "%s%s%s%s%s%d%f", current->num, current->name, current->aut, current->pub, current->cat, &current->count, &current->price) != EOF) {
		// 为当前节点分配内存

		// 检查当前图书是否与搜索查询匹配
		if (strcmp(query, current->num) == 0 || strcmp(query, current->name) == 0 || strcmp(query, current->aut) == 0 || strcmp(query, current->cat) == 0) {
			// 打印匹配的图书详情
			if (found == 0) {
				printf("\n搜索结果：\n\n");
				printf("书号\t书名   \t作者\t出版社\t类别\t现存量\t单价\n");
			}
			printf("%-8s%-30s%-10s%-30s%-30s%-7d%-8.2f\n", current->num, current->name, current->aut, current->pub, current->cat, current->count, current->price);
			found = 1;
		}

		// 将当前节点插入双向链表
		current->prev = NULL;
		current->next = head;
		if (head != NULL) {
			head->prev = current;
		}
		head = current;
	}
	fclose(fp);

	// 如果没有找到匹配的图书，则打印消息
	if (!found) {
		printf("\n未找到匹配记录！\n");
	}
	printf("\n按任意键返回");
	getch();
	AdministratorBookFunction();
}
void AdministratorVisitBook()//浏览图书
{
	FILE* fp;
	int n = 0;
	int k = 0, m = 0, count = 0;
	float price = 0;
	char  name[100] = { '\0' }, aut[100] = { '\0' }, cat[100] = { '\0' }, pub[100] = { '\0' }, num[100] = { '\0' };
	char i;
	if ((fp = fopen("library.txt", "r")) == NULL)//打开文件
	{
		system("cls");
		printf("\n记录文件不存在!按任意键返回");
		getch();//返回
		BookManageFunction();
	}
	n = statistic_book();
	if (n == 0)
	{
		system("cls");
		printf("\n无任何记录!");
	}

	fp = fopen("library.txt", "r");//打开只读文件
	system("cls");
	printf("书号\t书名\t作者\t\t出版社\t\t类别\t\t库存量\t单价\n");

	for (m = 0; m < n; m++)//输出数据
	{
		fscanf(fp, "%s%s%s%s%s%d%f", num, name, aut, pub, cat, &count, &price);
		printf("%-8s%-30s%-30s%-30s%-30s%-7d%-8.2f\n", num, name, aut, pub, cat, count, price);
	}
	fclose(fp);
	printf("\n按任意键返回\n");
	getch();
	AdministratorBookFunction();
}