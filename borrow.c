#include <stdio.h>
#include <stdlib.h>//���а���system����
#include <conio.h>//������ͨ������̨���� �������� ����������ĺ�������getch������
#include <string.h>//�����ַ�����
#include <math.h>
#include<time.h>
#define LEN1 sizeof(struct reader)//�йض�����Ϣ�Ľṹ��

#include "test.h"

extern int ReaderID;

void borrow_message()//����ϵͳ����
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



void borrow()//���麯��
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
		printf("\n ͼ����޿��!��������˳�!");
		getch();//��C++����У�getch()��һ�������������ڴӿ���̨��ȡ�û������һ���ַ�������ʾ����Ļ�ϲ��Ҳ���Ҫ���»س�����ͨ��������Ϸ��������Ҫ����ʽ����ĳ����С�����getch()������������ȡһ���ַ��������䷵�ظ����򣬳�����Ը����û�����Ĳ�ͬ�ַ�ִ����Ӧ�Ĳ�����
		exit(0);//exit(0)��C++�����е�һ�������������˳����򣬲�����һ��ֵ�����в���0��ʾ���������˳������������е�exit(0)ʱ������������˳��������ظ�����ϵͳһ��ֵ0����ʾ����ɹ�ִ����ϡ�
	}
	else
	{
		printf("\n�������������:\n������:");
		scanf("%s", znamee);
		k = statistic_book();//ͳ��ͼ����ļ�����

		for (i = 0; i < k; i++)//�Ƚ�ͼ����Ϣ�����������Ŀ��
		{
			fscanf(fp, "%s%s%s%s%s%d%f", tshuhao, tnamee, tauthor, tpublisher, tkind, &count, &tprice);
			n++;
			if (n == 1)
			{
				p1 = p2 = (struct book*)malloc(LEN);//�öδ�����һ�����ļ��ж�ȡ���ݲ���������Ĺ��̡����У�n��������¼��ȡ�����������ı�����

				//if�ж���������Ϊn�Ƿ����1��������Ϊ��nΪ1ʱ�������ǵ�һ�ζ�ȡ���ݣ���Ҫ���⴦����ʱ����Ҫͨ��malloc��̬�����ڴ���Ϊ�ṹ��book���͵ı���p1��p2����ռ䣬Ȼ��ͷָ��headָ��p1��

					//��n������1ʱ�������ǵ�һ�ζ�ȡ���ݣ���Ҫ����ǰ��ȡ���������ӵ������С���ʱ����ǰһ���ڵ�p2��nextָ��ָ��ǰ�ڵ�p1��������p2Ϊ��ǰ�ڵ�p1��Ȼ����Ϊ��һ�ζ�ȡ�����ݷ���ռ䡣
				head = p1;
			}//��δ�������C++��д�ģ���Ҫ�����ǽ�ͼ����Ϣ�����������Ŀ�档�ؼ��ְ���for��fscanf��malloc�ȡ�

			//�����������ͨ��ѭ����forѭ������ȡ�ļ�ָ��(fp)�е�ͼ����Ϣ���������(tshuhao)������(tnamee)������(tauthor)��������(tpublisher)������(tkind)������(count)�ͼ۸�(tprice)��ÿ��ѭ���������n��ֵ�����nΪ1��������ڴ�ռ��p1��p2�����ҽ�headָ��p1��

				//��δ���ľ��幦���ǽ���ȡ��ͼ����Ϣ�洢�������У�ÿ��ѭ�������½�һ������ڵ㲢��ӵ������У��Խ���������ͼ����Ϣ����
			else
			{
				p2->next = p1;
				p2 = p1;
				p1 = (struct book*)malloc(LEN);

			}//��δ���ʹ����C++��������̬����һ������������else����У���p1��ָ�Ľڵ㱣�浽p2��nextָ���У�Ȼ��p2ָ��p1������Ϊp1������һ���µĽڵ��ڴ�ռ䡣��δ����Ŀ���ǽ��·���Ľڵ���뵽�����ĩβ�����һ���ڵ��nextָ��ָ��NULL����ʾ����Ľ�����
			/*��δ�������C++��д�ģ����ڶ�ȡ�ļ��е��鼮��Ϣ���洢�������С������Ǵ������ϸ���ͣ�

				- `for (i=
0; i < k; i++)`: ����һ��forѭ����ѭ������Ϊi����0��ʼ�𲽵�����ֱ���ﵽk��ֵ��
				- `fscanf(fp, "%s%s%s%s%s%d%f", tshuhao, tnamee, tauthor, tpublisher, tkind, & count, & tprice)`: ���ļ�fp�а���ʽ"%s%s%s%s%s%d%f"��ȡ���ݣ�������ȡ�����ݷֱ�洢��tshuhao, tnamee, tauthor, tpublisher, tkind, count, tprice�С�
				- `n+ + `: ��������n����ʾ��ȡ���鼮������
				- `if (n == 1)`: ���n����1����ִ���������䡣
				- `p1 = p2 = (struct book*)malloc(LEN)`: ����һ����СΪLEN���ڴ�ռ䣬�����ַ��ֵ��ָ��p1��p2��
				- `head = p1`: ��ָ��p1�ĵ�ַ��ֵ��ָ��head����ʾ�����ͷ����
				- `else`: ���n������1����ִ���������䡣
				- `p2- > next = p1`: ��ָ��p1��ֵ��p2��nextָ�룬��ʾp2ָ��p1��
				- `p2 = p1`: ��ָ��p1�ĵ�ַ��ֵ��ָ��p2��������һ��ѭ����
				- `p1 = (struct book*)malloc(LEN)`: ����һ����СΪLEN���ڴ�ռ䣬�����ַ��ֵ��ָ��p1��������һ��ѭ����

				��δ���Ĺ��������ж�ȡ�ļ��е��鼮��Ϣ��Ȼ��ÿ�������Ϣ�洢��һ���ṹ��book�У����չ���һ������ṹ���öδ�����һ�����ļ��ж�ȡ���ݲ���������Ĺ��̡����У�n��������¼��ȡ�����������ı�����

if�ж���������Ϊn�Ƿ����1��������Ϊ��nΪ1ʱ�������ǵ�һ�ζ�ȡ���ݣ���Ҫ���⴦����ʱ����Ҫͨ��malloc��̬�����ڴ���Ϊ�ṹ��book���͵ı���p1��p2����ռ䣬Ȼ��ͷָ��headָ��p1��

��n������1ʱ�������ǵ�һ�ζ�ȡ���ݣ���Ҫ����ǰ��ȡ���������ӵ������С���ʱ����ǰһ���ڵ�p2��nextָ��ָ��ǰ�ڵ�p1��������p2Ϊ��ǰ�ڵ�p1��Ȼ����Ϊ��һ�ζ�ȡ�����ݷ���ռ䡣*/
			strcpy(p1->num, tshuhao);//�������
			strcpy(p1->name, tnamee);//��������
			strcpy(p1->aut, tauthor);//��������
			strcpy(p1->pub, tpublisher);//���Ƴ�����
			strcpy(p1->cat, tkind);//�������
			p1->count = count;//�����ִ���
			p1->price = tprice;//���Ƶ���
		}
		if (n == 0)
			head = NULL;
		else
		{
			p2->next = p1;
			p1->next = NULL;
			fclose(fp);
		}//��δ�����һ���򵥵�C++����Σ���Ҫ�����жϱ���n�Ƿ����0�����n����0����headָ��ָ��NULL�����򣬽�p1ָ���nextָ��ָ��p2����p1��nextָ��ָ��NULL�����ر��ļ�ָ��fp��

		//����δ����У�n����0����һ���������������ܱ�ʾ����Ϊ�ջ�������Ҫ���⴦������������ʵ�������������n����0ʱ�����뽫ִ�н�headָ��ָ��NULL�Ĳ����������������߽������⴦��



	}
	p = head;

	for (; p != NULL;)
	{
		if (!(strcmp(p->name, znamee)))//�ж�Ҫ������Ƿ���ڣ���ǵ���1�����ڿ���һ
		{

			flag = 1;
			loop = p->count;
			(p->count)--;
		}
		p = p->next;
	}
	if (flag && (loop > 0))//���ڱ����ͼ�����ִ�������0���ѿ�����仯�����������ļ�
	{

		
		

		static int i = 0;
		char filename[20];


		sprintf(filename, "%d.txt", ReaderID);//��δ���ʹ��sprintf��������һ������ֵID_card��ʽ����һ���ַ�������ƴ�ӵ�һ���̶����ַ���"reader%d.txt"�У����ս�������浽filename�����С�
		//-sprintf(filename, "%d.txt", ID_card) : �������������ʹ��sprintf������"reader%d.txt"�����ʽ�����ַ�����ID_card�������ֵ���и�ʽ��ƴ�ӣ�����������浽filename�����С����� % d�Ǹ�ʽ�����ţ���ʾ�����������ֵ��ʮ���������ĸ�ʽ���и�ʽ����

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
			time(&timep); //��ȡ��1970������˶����룬����time_t���͵�timep
			pp = localtime(&timep);//��localtime������ת��Ϊstruct tm�ṹ��

			printf("%d/%d/%d/%02d:%02d:%02d\n����ɹ���������������أ�", 1900 + pp->tm_year, 1 + pp->tm_mon, pp->tm_mday, pp->tm_hour, pp->tm_min, pp->tm_sec);
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
			printf("���������ѳ�������޶ȣ�����ʧ��");
			fclose(fp3);

		}

	}


	else
	{
		if (flag != 0)
			printf("�����ѱ�����!�����������!");//������������ѱ�����
		else
			printf("�����޴���!�����������");
	}
	getch();//����
	borrow_message();//���ý���ϵͳ
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
		printf("�����ļ������ڣ�");
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
						printf("���鱾����������޶ȣ�����ʧ��");
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
					else { printf("���鱾����������޶ȣ�����ʧ��"); return -1; }
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
						printf("���鱾����������޶ȣ�����ʧ��"); return-1;
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
						printf("���鱾����������޶ȣ�����ʧ��"); return -1;
					}
					break;
				}
				}
			}
		}

	}

}



void ReturnBook()//���麯��
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
		if (fp == NULL)//�����ڶ����ļ�����������ܻ���
		{
			system("cls");
			printf("\n �����ڽ�����!��������˳�!");
			getch();
			system("cls");
			borrow_message();
		}

		else
		{
			{
				printf("\n����������:\n������:");
				scanf("%s", inputBookName);//��������
				k = statistic_numBooks();//��ȡ�����ļ�����Ϣ����
				for (i = 0; i < k; i++)//��ȡ�����ļ�����Ϣ
				{
					fscanf(fp, "%s%s\n ", ttime, tznamee);
					if (strcmp(inputBookName, tznamee) == 0)//���֤���������ڣ�����Ϊ1
						flag = 1;
				}
				fclose(fp);
				fp = fopen(Filename, "r");//�򿪶����ļ���ɾ��������Ϣ
				if (flag)
				{
					for (i = 0; i < k; i++)//�����ļ����Ƶ�����
					{
						fscanf(fp, "%s%s\n ", ttime, tznamee);//��ȡ�ļ���Ϣ
						if (!strcmp(inputBookName, tznamee))
						{
							n++;
							if (n == 1)
							{
								p1 = p2 = (struct reader*)malloc(LEN1);//�½�����
								head = p1;
							}
							else
							{
								p2->next = p1;
								p2 = p1;
								p1 = (struct reader*)malloc(LEN1);//�½�����
							}
							strcpy(p1->time, ttime);//��������
							strcpy(p1->return_name, tznamee);//��������
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
					fp = fopen(Filename, "w");//��ն����ļ�
					fclose(fp);
					fp = fopen(Filename, "a");//׷����Ϣ
					p = head;
					for (; p != NULL;)//���������ݸ��Ƕ����ļ�
					{
						fprintf(fp, "\n%s %s\n", p->time, p->return_name);
						p = p->next;
					}
					free(p);
					fclose(fp);
				}}
		}}

	if (flag == 1)//���Ϊ1��������ʱ���Ŀ��
	{
		{
			{
				printf("ȷ�ϻ����밴�س�!");
				for (; hitkey != 13 && hitkey != 27;)
					hitkey = getch();
				if (hitkey == 13)
					printf("�ɹ�!�����������!");
				n = 0; flag = 0;
				fp3 = fopen("library.txt", "r");//��ͼ����ļ�
				k = statistic_book();//��ȡͼ����ļ�����
				for (i = 0; i < k; i++)//��ͼ����ļ����Ƶ�����
				{
					fscanf(fp3, "%s%s%s%s%s%d%f", tshuhao, tnamee, tauthor, tchuban, tkind, &txcl, &tprice);//��ȡ��Ϣ
					n++;
					if (n == 1)
					{
						lp1 = lp2 = (struct book*)malloc(LEN);//�½�����
						lhead1 = lp1;
					}
					else
					{
						lp2->next = lp1;
						lp2 = lp1;
						lp1 = (struct book*)malloc(LEN);//�½�����
					}
					strcpy(lp1->num, tshuhao);//�������
					strcpy(lp1->name, tnamee);//��������
					strcpy(lp1->aut, tauthor);//��������
					strcpy(lp1->pub, tchuban);//���Ƴ�����
					strcpy(lp1->cat, tkind);//�������
					lp1->count = txcl; //�����ִ���
					lp1->price = tprice;//���Ƶ���
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
		
		fp3 = fopen("library.txt", "w");//���ͼ����ļ�
		fclose(fp);
		fp3 = fopen("library.txt", "a");//׷����Ϣ
		zp1 = lhead1;
		for (; zp1 != NULL;)//���������ݸ���ͼ����ļ�
		{
			if (!(strcmp(zp1->name, inputBookName)))//Ѱ��������ͬ
				++(zp1->count);//�ִ�����1
			fprintf(fp3, "%s %s %s %s %s %d %.2f\n",
				zp1->num, zp1->name, zp1->aut, zp1->pub, zp1->cat, zp1->count, zp1->price);
			zp1 = zp1->next;
		}
		fclose(fp3);
		getch();//����
		borrow_message();//���ý���ϵͳ
	}
	else
		printf("�����ڴ���Ϣ!�����������!");
	getch();//����
	borrow_message();//���ý���ϵͳ
}


void visit_borrow()//��ʾ�����������

{
	FILE* fp;
	int ID = 0, xcl = 0, n = 0, i = 0, j = 0;
	char name[100] = { '\0' }, time[100] = { '\0' }, znamee[100] = { '\0' };
	char filename[100] = { 0 };
	itoa(ReaderID, filename, 10);
	strcat(filename, ".txt");
	fp = fopen(filename, "r");//���ļ�
	if (fp == NULL)//�򿪶����ļ���
	{
		system("cls");
		printf("\n��¼�ļ�������!�����������");
		getch();
		borrow_message();
	}
	n = statistic_numBooks();
	if (n == 0)
	{
		system("cls");
		printf("\n���κμ�¼!");
	}
	fp = fopen(filename, "r");
	system("cls");
	printf("\n\t��������      \t����\n");
	for (; !feof(fp);)//����ļ���Ϣ
	{
		fscanf(fp, "%s%s\n ", time, znamee);
		printf("\n%-18s%-10s\n", time, znamee);
	}
	fclose(fp);
	printf("\n�����������\n");
	getch();//����
	borrow_message();//���ý���ϵͳ
}




//ģ����ѯ
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
	if ((fp = fopen("library.txt", "r")) == NULL)//���ļ�
	{
		system("cls");
		printf("\n��¼�ļ�������!�����������");
		getch();
		BookManageFunction();
	}
	system("cls");
	printf("����������Ҫ��ѯ�����к��е��֣�");
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

				printf("���\t����\t����\t\t������\t\t���\t\t�ִ���\t����\n");
			}
			printf("%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", num, name, aut, pub, cat, count, price);
			k++;
		}

	}
	if (k == 0)//�ļ���Ϊ��������޼�¼��������һ��
	{
		system("cls");
		printf("\n�޷��ϼ�¼!\n");
		getch();
		BookManageFunction();
	}
	fclose(fp);//��ѯ����
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
	fp = fopen(filename, "r");//���ļ�
	for (n = 0; !feof(fp); n++)//������ļ�
		fscanf(fp, " %s %s",time, znamee);

	fclose(fp);//�ر��ļ�
	return (n);//���ظ���
}


