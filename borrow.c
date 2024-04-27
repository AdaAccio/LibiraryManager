#include <stdio.h>
#include <stdlib.h>//其中包含system函数
#include <conio.h>//定义了通过控制台进行 数据输入 和数据输出的函数，如getch函数。
#include <string.h>//定义字符数组
#include <math.h>
#include<time.h>
#define LEN1 sizeof(struct reader)//有关读者信息的结构体

#include "test.h"

extern int ReaderID;

void borrow_message()//借阅系统函数
{
	void borrow();
	void ReturnBook();
	void visit_borrow();
	void inquire();
	char choose;
	BorrowMenu();
	scanf(" %c", &choose);
	for (;;)
	{
		switch (choose)
		{
		case'1':
			borrow();
			break;
		case'2':
			ReturnBook();
			break;
		case'3':
			visit_borrow();
			break;
		case'4':
			ReaderMainFunction();
			break;
		}
	}

}



void borrow()//借书函数
{
	FILE* fp, * fp3;
	struct book* head = NULL;
	struct book* p, * p1 = NULL, * p2 = NULL;
	int i, loop, k, n = 0, flag = 0, s = 0;
	int ID_card = 0;
	int count = 0;
	float tprice = 0;
	char tnamee[100] = { '\0' }, tauthor[100] = { '\0' }, tkind[100] = { '\0' }, tpublisher[100] = { '\0' }, tshuhao[100] = { '\0' },
		ttnamee[100] = { '\0' }, name[100] = { '\0' }, b_time[100] = { '\0' }, znamee[100] = { '\0' };
	char hit = 0;


	system("cls");
	if ((fp = fopen("library.txt", "r")) == NULL)
	{
		system("cls");
		printf("\n 图书馆无库存!按任意键退出!");
		getch();//在C++编程中，getch()是一个函数，它用于从控制台获取用户输入的一个字符，不显示在屏幕上并且不需要按下回车键。通常用于游戏开发或需要交互式输入的程序中。调用getch()函数会立即读取一个字符，并将其返回给程序，程序可以根据用户输入的不同字符执行相应的操作。
		exit(0);//exit(0)是C++语言中的一个函数，用来退出程序，并返回一个值。其中参数0表示程序正常退出。当程序运行到exit(0)时，程序会立即退出，并返回给操作系统一个值0，表示程序成功执行完毕。
	}
	else
	{
		printf("\n请输入借阅书名:\n请输入:");
		scanf("%s", znamee);
		k = statistic_book();//统计图书馆文件个数

		for (i = 0; i < k; i++)//先将图书信息建立链表，更改库存
		{
			fscanf(fp, "%s%s%s%s%s%d%f", tshuhao, tnamee, tauthor, tpublisher, tkind, &count, &tprice);
			n++;
			if (n == 1)
			{
				p1 = p2 = (struct book*)malloc(LEN);//该段代码是一个从文件中读取数据并构建链表的过程。其中，n是用来记录读取的数据条数的变量。

				//if判断语句的条件为n是否等于1，这是因为当n为1时，代表是第一次读取数据，需要特殊处理。此时，需要通过malloc动态分配内存来为结构体book类型的变量p1和p2分配空间，然后将头指针head指向p1。

					//当n不等于1时，代表不是第一次读取数据，需要将当前读取的数据链接到链表中。此时，将前一个节点p2的next指针指向当前节点p1，并更新p2为当前节点p1，然后再为下一次读取的数据分配空间。
				head = p1;
			}//这段代码是用C++编写的，主要功能是将图书信息建立链表并更改库存。关键字包括for、fscanf、malloc等。

			//代码的作用是通过循环（for循环）读取文件指针(fp)中的图书信息，包括书号(tshuhao)、书名(tnamee)、作者(tauthor)、出版社(tpublisher)、种类(tkind)、数量(count)和价格(tprice)。每次循环都会递增n的值，如果n为1，则分配内存空间给p1和p2，并且将head指向p1。

				//这段代码的具体功能是将读取的图书信息存储到链表中，每次循环都会新建一个链表节点并添加到链表中，以建立完整的图书信息链表。
			else
			{
				p2->next = p1;
				p2 = p1;
				p1 = (struct book*)malloc(LEN);

			}//这段代码使用了C++语言来动态创建一个链表。首先在else语句中，将p1所指的节点保存到p2的next指针中，然后将p2指向p1，接着为p1分配了一个新的节点内存空间。这段代码的目的是将新分配的节点插入到链表的末尾。最后一个节点的next指针指向NULL，表示链表的结束。
			/*这段代码是用C++编写的，用于读取文件中的书籍信息并存储在链表中。下面是代码的详细解释：

				- `for (i=
0; i < k; i++)`: 这是一个for循环，循环变量为i，从0开始逐步递增，直到达到k的值。
				- `fscanf(fp, "%s%s%s%s%s%d%f", tshuhao, tnamee, tauthor, tpublisher, tkind, & count, & tprice)`: 从文件fp中按格式"%s%s%s%s%s%d%f"读取数据，并将读取的数据分别存储在tshuhao, tnamee, tauthor, tpublisher, tkind, count, tprice中。
				- `n+ + `: 自增变量n，表示读取的书籍数量。
				- `if (n == 1)`: 如果n等于1，则执行下面的语句。
				- `p1 = p2 = (struct book*)malloc(LEN)`: 分配一个大小为LEN的内存空间，将其地址赋值给指针p1和p2。
				- `head = p1`: 将指针p1的地址赋值给指针head，表示链表的头部。
				- `else`: 如果n不等于1，则执行下面的语句。
				- `p2- > next = p1`: 将指针p1赋值给p2的next指针，表示p2指向p1。
				- `p2 = p1`: 将指针p1的地址赋值给指针p2，用于下一次循环。
				- `p1 = (struct book*)malloc(LEN)`: 分配一个大小为LEN的内存空间，将其地址赋值给指针p1，用于下一次循环。

				这段代码的功能是逐行读取文件中的书籍信息，然后将每本书的信息存储在一个结构体book中，最终构成一个链表结构。该段代码是一个从文件中读取数据并构建链表的过程。其中，n是用来记录读取的数据条数的变量。

if判断语句的条件为n是否等于1，这是因为当n为1时，代表是第一次读取数据，需要特殊处理。此时，需要通过malloc动态分配内存来为结构体book类型的变量p1和p2分配空间，然后将头指针head指向p1。

当n不等于1时，代表不是第一次读取数据，需要将当前读取的数据链接到链表中。此时，将前一个节点p2的next指针指向当前节点p1，并更新p2为当前节点p1，然后再为下一次读取的数据分配空间。*/
			strcpy(p1->num, tshuhao);//复制书号
			strcpy(p1->name, tnamee);//复制书名
			strcpy(p1->aut, tauthor);//复制作者
			strcpy(p1->pub, tpublisher);//复制出版社
			strcpy(p1->cat, tkind);//复制类别
			p1->count = count;//复制现存量
			p1->price = tprice;//复制单价
		}
		if (n == 0)
			head = NULL;
		else
		{
			p2->next = p1;
			p1->next = NULL;
			fclose(fp);
		}//这段代码是一个简单的C++程序段，主要是在判断变量n是否等于0，如果n等于0，则将head指针指向NULL；否则，将p1指针的next指针指向p2，将p1的next指针指向NULL，并关闭文件指针fp。

		//在这段代码中，n等于0代表一种特殊的情况，可能表示链表为空或者是需要特殊处理的情况。根据实际情况来看，当n等于0时，代码将执行将head指针指向NULL的操作，以清空链表或者进行特殊处理。



	}
	p = head;

	for (; p != NULL;)
	{
		if (!(strcmp(p->name, znamee)))//判断要借书的是否存在，标记等于1，存在库存减一
		{

			flag = 1;
			loop = p->count;
			(p->count)--;
		}
		p = p->next;
	}
	if (flag && (loop > 0))//存在被借的图书且现存量大于0，把库存量变化后的链表存入文件
	{

		
		

		static int i = 0;
		char filename[20];


		sprintf(filename, "%d.txt", ReaderID);//这段代码使用sprintf函数来将一个整数值ID_card格式化成一个字符串，并拼接到一个固定的字符串"reader%d.txt"中，最终将结果保存到filename变量中。
		//-sprintf(filename, "%d.txt", ID_card) : 这句代码的作用是使用sprintf函数将"reader%d.txt"这个格式化的字符串与ID_card这个整数值进行格式化拼接，并将结果保存到filename变量中。其中 % d是格式化符号，表示将后面的整数值以十进制整数的格式进行格式化。

		fp3 = fopen(filename, "r");
		if (fp3 == NULL) {
			printf("Error opening file!");
			exit(1);
		}

		int f = LimitBook();
		if (f != -1)
		{
			time_t timep;
			struct tm* pp;
			fp3 = fopen(filename, "a");
			time(&timep); //获取从1970至今过了多少秒，存入time_t类型的timep
			pp = localtime(&timep);//用localtime将秒数转化为struct tm结构体

			printf("%d/%d/%d/%02d:%02d:%02d\n借书成功！输入任意键返回！", 1900 + pp->tm_year, 1 + pp->tm_mon, pp->tm_mday, pp->tm_hour, pp->tm_min, pp->tm_sec);
			fprintf(fp3, "%d/%d/%d/%02d:%02d:%02d %s\n", 1900 + pp->tm_year, 1 + pp->tm_mon, pp->tm_mday, pp->tm_hour, pp->tm_min, pp->tm_sec, znamee);
			fclose(fp3);
			fp = fopen("library.txt", "w");
			fclose(fp);
			fp = fopen("library.txt", "a");
			p = head;

			for (; p != NULL;)
			{
				fprintf(fp, "%s %s %s %s %s %d %f\n", p->num, p->name, p->aut, p->pub, p->cat, p->count, p->price);
				p = p->next;
			}
			free(p);
			fclose(fp);
		}
		else {
			printf("借书数量已超出最大限度，借书失败");
			fclose(fp3);

		}

	}


	else
	{
		if (flag != 0)
			printf("此书已被借完!按任意键返回!");//否则输出此书已被借完
		else
			printf("查找无此书!按任意键返回");
	}
	getch();//返回
	borrow_message();//调用借阅系统
}
int LimitBook()
{

	int TempType;
	int TempID;
	char TempName[100];
	int ReaderCount = statistic_reader();
	char Filename[1000] = { 0 };
	itoa(ReaderID, Filename, 10);
	strcat(Filename, ".txt");
	FILE* fp1 = fopen(Filename, "r");
	FILE* fp2, * fp3;
	fp2 = fopen("reader.txt", "r");
	if (fp2 == NULL)
	{
		printf("读者文件不存在！");
	}
	else
	{
		for (int i = 0; i < ReaderCount; i++)
		{
			fscanf(fp2, "%d %s %d", &TempID, TempName, &TempType);
			if (TempID == ReaderID)
			{
				int type = TempType;
				int n = statistic_numBooks();
				switch (type)
				{
				case 0:
				{
					if (n >= 0 && n < 15)
					{
						getch();
						system("cls");
						return 0;
					}
					else {
						printf("借书本数超出最大限度，借书失败");
						return -1; }
					break;
				}
				case 1:
				{
					if (n >= 0 && n < 20)
					{
						getch();
						system("cls");
						return 1;
					}
					else { printf("借书本数超出最大限度，借书失败"); return -1; }
					break;
				}
				case 2:
				{
					if (n >= 0 && n < 25)
					{
						getch();
						system("cls");
						return 2;
					}
					else {
						printf("借书本数超出最大限度，借书失败"); return-1;
					}
					break;
				}
				case 3:
				{
					if (n >= 0 && n < 30)
					{
						getch();
						system("cls");
						return 3;
					}
					else {
						printf("借书本数超出最大限度，借书失败"); return -1;
					}
					break;
				}
				}
			}
		}

	}

}



void ReturnBook()//还书函数
{
	FILE* fp3;
	struct reader* head = NULL;
	struct reader* p, * p1 = NULL, * p2 = NULL;
	struct book* lhead1 = NULL;
	struct book* zp1, * lp1 = NULL, * lp2 = NULL;
	int txcl = 0, i;
	int judge = 0;
	float tprice = 0;
	char tnamee[100] = { '\0' }, tauthor[100] = { '\0' }, tkind[100] = { '\0' },
		tchuban[100] = { '\0' }, ttnamee[100] = { '\0' }, tshuhao[100] = { '\0' };
	int  n = 0, k = 0, t = 0, flag = 0;
	char tname[100] = { '\0' }, ttime[100] = { '\0' }, tznamee[100] = { '\0' }, inputBookName[100] = { '\0' };
	char hitkey = 0;
	char Filename[1000] = { 0 };
	itoa(ReaderID, Filename, 10);
	strcat(Filename, ".txt");
	FILE* fp = fopen(Filename, "r");
	system("cls");
	{
		if (fp == NULL)//不存在读者文件，则输出不能还书
		{
			system("cls");
			printf("\n 不存在借书者!按任意键退出!");
			getch();
			system("cls");
			borrow_message();
		}

		else
		{
			{
				printf("\n请输入书名:\n请输入:");
				scanf("%s", inputBookName);//输入书名
				k = statistic_numBooks();//获取读者文件夹信息个数
				for (i = 0; i < k; i++)//读取读者文件夹信息
				{
					fscanf(fp, "%s%s\n ", ttime, tznamee);
					if (strcmp(inputBookName, tznamee) == 0)//如果证号书名存在，则标记为1
						flag = 1;
				}
				fclose(fp);
				fp = fopen(Filename, "r");//打开读者文件，删除借书信息
				if (flag)
				{
					for (i = 0; i < k; i++)//将读文件复制到链表
					{
						fscanf(fp, "%s%s\n ", ttime, tznamee);//读取文件信息
						if (!strcmp(inputBookName, tznamee))
						{
							n++;
							if (n == 1)
							{
								p1 = p2 = (struct reader*)malloc(LEN1);//新建链表
								head = p1;
							}
							else
							{
								p2->next = p1;
								p2 = p1;
								p1 = (struct reader*)malloc(LEN1);//新建链表
							}
							strcpy(p1->time, ttime);//复制日期
							strcpy(p1->return_name, tznamee);//复制书名
						}
					}
					if (n == 0)
						head = NULL;
					else
					{
						p2->next = p1;
						p1->next = NULL;
						fclose(fp);
					}
					fp = fopen(Filename, "w");//清空读者文件
					fclose(fp);
					fp = fopen(Filename, "a");//追加信息
					p = head;
					for (; p != NULL;)//把链表内容覆盖读者文件
					{
						fprintf(fp, "\n%s %s\n", p->time, p->return_name);
						p = p->next;
					}
					free(p);
					fclose(fp);
				}}
		}}

	if (flag == 1)//标记为1，即还书时更改库存
	{
		{
			{
				printf("确认还书请按回车!");
				for (; hitkey != 13 && hitkey != 27;)
					hitkey = getch();
				if (hitkey == 13)
					printf("成功!按任意键返回!");
				n = 0; flag = 0;
				fp3 = fopen("library.txt", "r");//打开图书馆文件
				k = statistic_book();//获取图书馆文件个数
				for (i = 0; i < k; i++)//将图书馆文件复制到链表
				{
					fscanf(fp3, "%s%s%s%s%s%d%f", tshuhao, tnamee, tauthor, tchuban, tkind, &txcl, &tprice);//读取信息
					n++;
					if (n == 1)
					{
						lp1 = lp2 = (struct book*)malloc(LEN);//新建链表
						lhead1 = lp1;
					}
					else
					{
						lp2->next = lp1;
						lp2 = lp1;
						lp1 = (struct book*)malloc(LEN);//新建链表
					}
					strcpy(lp1->num, tshuhao);//复制书号
					strcpy(lp1->name, tnamee);//复制书名
					strcpy(lp1->aut, tauthor);//复制作者
					strcpy(lp1->pub, tchuban);//复制出版社
					strcpy(lp1->cat, tkind);//复制类别
					lp1->count = txcl; //复制现存量
					lp1->price = tprice;//复制单价
				}
				if (n == 0)
				{
					lhead1 = NULL;
				}
				else
				{
					lp2->next = lp1;
					lp1->next = NULL;
					fclose(fp3);
				}}}
		zp1 = lhead1;
		
		fp3 = fopen("library.txt", "w");//清空图书馆文件
		fclose(fp);
		fp3 = fopen("library.txt", "a");//追加信息
		zp1 = lhead1;
		for (; zp1 != NULL;)//把链表内容覆盖图书馆文件
		{
			if (!(strcmp(zp1->name, inputBookName)))//寻找书名相同
				++(zp1->count);//现存量加1
			fprintf(fp3, "%s %s %s %s %s %d %.2f\n",
				zp1->num, zp1->name, zp1->aut, zp1->pub, zp1->cat, zp1->count, zp1->price);
			zp1 = zp1->next;
		}
		fclose(fp3);
		getch();//返回
		borrow_message();//调用借阅系统
	}
	else
		printf("不存在此信息!按任意键返回!");
	getch();//返回
	borrow_message();//调用借阅系统
}


void visit_borrow()//显示借书情况函数

{
	FILE* fp;
	int ID = 0, xcl = 0, n = 0, i = 0, j = 0;
	char name[100] = { '\0' }, time[100] = { '\0' }, znamee[100] = { '\0' };
	char filename[100] = { 0 };
	itoa(ReaderID, filename, 10);
	strcat(filename, ".txt");
	fp = fopen(filename, "r");//打开文件
	if (fp == NULL)//打开读者文件夹
	{
		system("cls");
		printf("\n记录文件不存在!按任意键返回");
		getch();
		borrow_message();
	}
	n = statistic_numBooks();
	if (n == 0)
	{
		system("cls");
		printf("\n无任何记录!");
	}
	fp = fopen(filename, "r");
	system("cls");
	printf("\n\t借书日期      \t书名\n");
	for (; !feof(fp);)//输出文件信息
	{
		fscanf(fp, "%s%s\n ", time, znamee);
		printf("\n%-18s%-10s\n", time, znamee);
	}
	fclose(fp);
	printf("\n按任意键返回\n");
	getch();//返回
	borrow_message();//调用借阅系统
}




//模糊查询
void vague()
{
	FILE* fp;
	int k = 0, count = 0, m = 0, n = 0, p = 0, q, p1 = 0, q1 = 0, p2 = 0;
	int end = 0;
	float price = 0;
	char  name[100] = { '\0' }, aut[100] = { '\0' }, cat[100] = { '\0' }, pub[100] = { '\0' }, num[100] = { '\0' };
	char i;
	char ch[100] = { '\0' };
	char* ch1;
	if ((fp = fopen("library.txt", "r")) == NULL)//打开文件
	{
		system("cls");
		printf("\n记录文件不存在!按任意键返回");
		getch();
		BookManageFunction();
	}
	system("cls");
	printf("请输入你想要查询的书中含有的字：");
	scanf("%s", ch);
	q1 = strlen(ch);
	system("cls");
	m = statistic_book();
	for (n = 0; n < m; n++)
	{
		end = 0;
		p2 = 0;
		p1 = 0;
		fscanf(fp, "%s%s%s%s%s%d%f", num, name, aut, pub, cat, &count, &price);
		q = strlen(name);
		while (p2 != q1)
		{
			while (p1 != q)
			{
				if (ch[p2] == name[p1])
				{
					end++;
					p1++;
					break;
				}
				else
					p1++;
			}
			p2++;
		}
		if (end == q1)
		{
			if (k == 0)
			{

				printf("书号\t书名\t作者\t\t出版社\t\t类别\t\t现存量\t单价\n");
			}
			printf("%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", num, name, aut, pub, cat, count, price);
			k++;
		}

	}
	if (k == 0)//文件夹为空则输出无记录并返回上一层
	{
		system("cls");
		printf("\n无符合记录!\n");
		getch();
		BookManageFunction();
	}
	fclose(fp);//查询结束
	getch();
	BookManageFunction();
}
int statistic_numBooks()
{
	FILE* fp;
	int inputID = 0, n;
	char name[100] = { 0 };
	char time[100] = { 0 };
	char znamee[100] = { 0 };
	char code[100] = { '\0' };
	char filename[100] = { 0 };
	itoa(ReaderID, filename, 10);
	strcat(filename, ".txt");
	fp = fopen(filename, "r");//打开文件
	for (n = 0; !feof(fp); n++)//逐个读文件
		fscanf(fp, " %s %s",time, znamee);

	fclose(fp);//关闭文件
	return (n);//返回个数
}


