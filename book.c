#include <stdio.h>
#include <stdlib.h>//其中包含system函数
#include <conio.h>//定义了通过控制台进行 数据输入 和数据输出的函数，如getch函数。
#include <string.h>//定义字符数组
#include <math.h>
#include <assert.h>

#define LEN sizeof(struct book)//有关图书信息的结构体
#include "test.h"
void SortMenu()
{
	system("cls");
	printf("*****************************************************");
	printf("\t\t\n\n请选择排序方式：\n\n");
	printf("\t\t\n\n1.按作者名排序\n\n");
	printf("\t\t\n\n2.按书号排序\n\n");
	printf("\t\t\n\n3.返回上一层\n\n");
	printf("\t\t\n\n请按键选择，回车确定\n\n");
	printf("*****************************************************");
}

//struct BookNode* head = NULL;
void inquire()//查询借书
{
	FILE* fp;
	char filename[100] = { 0 };
	int ID;
	printf("请输入想要查询的读者ID\n");
	scanf("%d", &ID);
	itoa(ID, filename, 10);
	strcat(filename, ".txt");
	fp = fopen(filename, "r");//打开文件
	int borrownum = 0, k = 0, count = 0, m = 0, n = 0;
	char  borrowname[100] = { '\0' }, borrowtime[100] = { '\0' }, return_name[100] = { '\0' };
	char i;
	char cz[100] = { '\0' };
	if ((fp = fopen(filename, "r")) == NULL)//打开文件
	{
		system("cls");
		printf("\n记录文件不存在!按任意键返回");
		getch();
		borrow_message();
	}
	system("cls");
	printf("查询结果:\n\n");
	for (; !feof(fp);)
	{
		fscanf(fp, "%s%s", borrowtime, return_name);
		printf("\n\t借书日期\t书名\n");
		printf("\n%-18s%-10s\n", borrowtime, return_name);
		k++;

	}
	if (k == 0)//文件夹为空则输出无记录并返回上一层
	{
		system("cls");
		printf("\n无符合记录!\n");
		getch();
		borrow_message();
	}
	fclose(fp);//查询结束
	getch();
	ReaderFunction();
}


int statistic_book()//统计图书文本个数
{
	FILE* fp;
	int t = 0, n;
	float price = 0;
	char name[100] = { '\0' }, author[100] = { '\0' }, publisher[100] = { '\0' }, kind[100] = { '\0' }, number[100] = { '\0' };
	fp = fopen("library.txt", "r");//打开文件
	for (n = 0; !feof(fp); n++)//逐个读文件
		fscanf(fp, "%s%s%s%s%s%d%f", number, name, author, publisher, kind, &t, &price);
	fclose(fp);//关闭文件
	return (n);//返回个数
}


int statistic_reader()//统计文读者本个数函数

{
	FILE* fp;
	int ID_card = 0, n;
	int type;
	char name1[100] = { '\0' }, time[100] = { '\0' }, name2[100] = { '\0' };
	fp = fopen("reader.txt", "r");//打开文件
	for (n = 0; !feof(fp); n++)//逐个读文件
		fscanf(fp, "%d%s%d", &ID_card, &name1, &type);
	n--;
	fclose(fp);//关闭文件
	return (n);//返回个数
}


int statistic_book3()//统计账号密码文本个数
{
	FILE* fp;
	int ID = 0, n;
	char code[100] = { '\0' };
	fp = fopen("land.txt", "r");//打开文件
	for (n = 0; !feof(fp); n++)//逐个读文件
		fscanf(fp, "%d %s", &ID, code);
	n--;
	fclose(fp);//关闭文件
	return (n);//返回个数
}



void adds()//增加图书
{
	FILE* fp;
	char i = '0';
	int many = 0;
	float price = 0;
	float price1 = 0;
	int t = 0;
	char  nam[100] = { '\0' }, aut[100] = { '\0' }, cat[100] = { '\0' }, pub[100] = { '\0' }, num[100] = { '\0' };
	char  name[100] = { '\0' }, author[100] = { '\0' }, kind[100] = { '\0' }, publish[100] = { '\0' }, number[100] = { '\0' };
	system("cls");

	if ((fp = fopen("library.txt", "r+")) == NULL)//if语句：打开图书馆文件，不存在此文件则新建
	{
		//fp = fopen("library.txt", "r+");
		fclose(fp);
	}
	//fp = fopen("library.txt", "r+");

	printf("\n请按以下格式输入图书信息:\n书号 书名 作者 出版社 类别 进库量 单价");

	for (; i != 27;)//为了实现输入一次后按esc退出
	{
		printf("请输入:\n");
		scanf("%s%s%s%s%s%d%f", num, nam, aut, pub, cat, &many, &price);
		int flag = 0;
		fp = fopen("library.txt", "r+");
		for (int n = 0; !feof(fp); n++)//逐个读文件
		{
			//printf("1");
			fscanf(fp, "%s%s%s%s%s%d%f", number, name, author, publish, kind, &t, &price1);
			if (atoi(num) == atoi(number))
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			printf("该序号已存在，重新输入请按回车，结束输入请按Esc\n");
			i = getch();//暂停程序当i接收后继续下一条指令
			for (; i != 13 && i != 27;)//保证只能是CR和ESC才能退出循环,输入其他字符无用，暂停程序，按'CR'继续。
				i = getch();
			fclose(fp);
			continue;
		}

		fprintf(fp, "%-20s %-20s %-20s %-20s %-20s %-7d %-8.2f\n", num, nam, aut, pub, cat, many, price);
		fclose(fp);
		printf("继续输入请按回车，结束输入请按Esc\n");
		i = getch();//暂停程序当i接收后继续下一条指令
		for (; i != 13 && i != 27;)//保证只能是CR和ESC才能退出循环,输入其他字符无用，暂停程序，按'CR'继续。
			i = getch();
	}

	fclose(fp);
	printf("\n保存成功，按任意键返回上一层!");
	getch();
	AdministratorBookFunction();//返回上一层
}

void removes()//删除图书
{
	int flag = 1;//判断记录
	struct book* head = NULL;
	struct book* p, * p1 = NULL, * p2 = NULL;
	int tcount = 0, n = 0, j, k;
	float tprice = 0;
	char  tname[100] = { '\0' }, taut[100] = { '\0' }, tcat[100] = { '\0' }, tpub[100] = { '\0' }, tnum[100] = { '\0' };
	char jborrow_name[100] = { '\0' };
	char i;
	FILE* fp;
	if ((fp = fopen("library.txt", "r")) == NULL)//打开文件
	{
		system("cls");
		printf("\n记录文件不存在!按任意键返回");
		getch();
		BookManageFunction();
	}

	else//实现删除的功能
	{
		system("cls");
		printf("\n请输入你要删除的书名:");//输入删除图书书名
		scanf("%s", jborrow_name);
		printf("\n确认删除请回车，取消请按Esc\n");
		i = getch();
		for (; i != 13 && i != 27;)
			i = getch();
		if (i == 27)
			BookManageFunction();
		fp = fopen("library.txt", "r");
		j = statistic_book();

		for (k = 0; k < j; k++)
		{
			fscanf(fp, "%s%s%s%s%s%d%f", tnum, tname, taut, tpub, tcat, &tcount, &tprice);
			if (strcmp(jborrow_name, tname))//比较名字，将不同名字的信息复制到链表
			{
				n++;//相同返回值为0不执行if语句继续循环，不同则执行直到将所有不同的书名建立成链表
				if (n == 1)//建立链表
				{
					p1 = p2 = (struct book*)malloc(LEN);
					head = p1;
				}
				else
				{
					p2->next = p1;
					p2 = p1;
					p1 = (struct book*)malloc(LEN);//新建链表
				}

				strcpy(p1->num, tnum);//复制书号
				strcpy(p1->name, tname);//复制书名
				strcpy(p1->aut, taut);//复制作者名字
				strcpy(p1->pub, tpub);//复制出版社
				strcpy(p1->cat, tcat);//复制类别
				p1->count = tcount;//复制个数
				p1->price = tprice;//复制单价
			}
		}
		if (n == 0)//如果图书只有一项且这一项刚好和要删除的相同
		{
			head = NULL;
		}
		else//建立链表的最后剩余一个储存空间，所以封底
		{
			p2->next = p1;
			p1->next = NULL;
			fclose(fp);
		}
		if (n == j)
			flag = 0;
	}

	fp = fopen("library.txt", "w");//清空文件，只写打开，然后关闭
	fclose(fp);
	fp = fopen("library.txt", "a");//追加文件
	p = head;

	for (; p != NULL;)//把链表内容覆盖到文件
	{
		fprintf(fp, "%-30s %-30s %-30s %-30s %-30s %-7d %-8.2f\n", p->num, p->name, p->aut, p->pub, p->cat, p->count, p->price);
		p = p->next;
	}
	fclose(fp);
	system("cls");
	if (flag)
		printf("\n删除成功 \n按任意键返回上一层\n");
	else
		printf("\n该书不存在，无法删除！\n");
	getch();//返回上一层
	AdministratorBookFunction();
}


void search() {
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
	BookManageFunction();
}

void visit()//浏览图书
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
	BookManageFunction();
}
struct BookNode* sort_by_num(struct BookNode* head) {
	struct BookNode*p1, * p2, * p, * temp;
	int n = statistic_book();
	int count = 0;
	p = head, p1 = head->next, p2 = p1->next;
	while (count <= n - 1)
	{
		while (p2->next != 0)
		{
			if (strcmp(p1->num, p2->num) > 0)
			{
				p1->next = p2->next;
				p2->next = p->next;
				p->next = p2;
				temp = p2;
				p2 = p1;
				p1 = temp;
			}
			p = p->next, p1 = p1->next, p2 = p2->next;
		}
		if ((strcmp(p1->num, p2->num)>0) && p2->next == 0)
		{
			p1->next = p2->next;
			p2->next = p->next;
			p->next = p2;
			temp = p2;
			p2 = p1;
			p1 = temp;
		}
		p = head, p1 = head->next, p2 = p1->next, count++;
	}
	return head;
}

//按作者名排序
struct BookNode* sort_by_aut(struct BookNode* head) {
	struct BookNode* p1, * p2, * p, * temp;
	int n = statistic_book();
	int count = 0;
	p = head, p1 = head->next, p2 = p1->next;
	while (count <= n - 1)
	{
		while (p2->next != 0)
		{
			if (strcmp(p1->aut, p2->aut) > 0)
			{
				p1->next = p2->next;
				p2->next = p->next;
				p->next = p2;
				temp = p2;
				p2 = p1;
				p1 = temp;
			}
			p = p->next, p1 = p1->next, p2 = p2->next;
		}
		if ((strcmp(p1->aut, p2->aut) > 0) && p2->next == 0)
		{
			p1->next = p2->next;
			p2->next = p->next;
			p->next = p2;
			temp = p2;
			p2 = p1;
			p1 = temp;
		}
		p = head, p1 = head->next, p2 = p1->next, count++;
	}
	return head;
}
	

void sort()
{
	system("cls");
	FILE* fp;
	struct BookNode* p, * head = NULL;
	char num[100], name[100], aut[100], pub[100], cat[100];
	int count;
	float price;
	int flag = 0;
	char sort_option;

	fp = fopen("library.txt", "r");
	if (fp == NULL) {
		printf("无法打开文件\n");
		return;
	}

	printf("请选择排序方式：\n1.按书号排序\n2.按作者名排序\n");
	scanf(" %c", &sort_option);
	struct BookNode * p1 = NULL, * p2 = NULL;

	int k = statistic_book();//统计图书馆文件个数
	int n = 0;
	for (int i = 0; i < k; i++)//先将图书信息建立链表，更改库存
	{
		fscanf(fp, "%s%s%s%s%s%d%f", num, name, aut, pub, cat, &count, &price);
		n++;
		if (n == 1)
		{
			p1 = p2 = (struct BookNode*)malloc(sizeof(struct BookNode));//该段代码是一个从文件中读取数据并构建链表的过程。其中，n是用来记录读取的数据条数的变量。

				head = p1;
		}	
		else
		{
			p2->next = p1;
			p2 = p1;
			p1 = (struct BookNode*)malloc(sizeof(struct BookNode));

		}	
		strcpy(p1->num, num);//复制书号
		strcpy(p1->name, name);//复制书名
		strcpy(p1->aut, aut);//复制作者
		strcpy(p1->pub, pub);//复制出版社
		strcpy(p1->cat, cat);//复制类别
		p1->count = count;//复制现存量
		p1->price = price;//复制单价
	}
	if (n == 0)
		head = NULL;
	else
	{
		p2->next = p1;
		p1->next = NULL;
		fclose(fp);
	}




	switch (sort_option)
	{
	case '1': // 按书号排序
		head=sort_by_num(head);
		break;
	case '2': // 按作者名排序
		head=sort_by_aut(head);
		break;
	default:
		printf("输入错误！\n");
		return;
	}

	fp = fopen("library.txt", "w");
	if (fp == NULL) {
		printf("无法打开文件\n");
		return;
	}

	struct BookNode* temp = head;
	while (temp!= NULL) {
		fprintf(fp, "\n%s %s %s %s %s %d %.2f", temp->num, temp->name, temp->aut, temp->pub, temp->cat, temp->count, temp->price);
		struct BookNode* to_free = temp;
		temp = temp->next;
		free(to_free);
	}

	fclose(fp);

	printf("排序成功！\n");
	getch();
	system("cls");
	BookManageFunction();
}

