#include <stdio.h>
#include <stdlib.h>//���а���system����
#include <conio.h>//������ͨ������̨���� �������� ����������ĺ�������getch������
#include <string.h>//�����ַ�����
#include <math.h>
#include <assert.h>

#define LEN sizeof(struct book)//�й�ͼ����Ϣ�Ľṹ��
#include "test.h"
void SortMenu()
{
	system("cls");
	printf("*****************************************************");
	printf("\t\t\n\n��ѡ������ʽ��\n\n");
	printf("\t\t\n\n1.������������\n\n");
	printf("\t\t\n\n2.���������\n\n");
	printf("\t\t\n\n3.������һ��\n\n");
	printf("\t\t\n\n�밴��ѡ�񣬻س�ȷ��\n\n");
	printf("*****************************************************");
}

//struct BookNode* head = NULL;
void inquire()//��ѯ����
{
	FILE* fp;
	char filename[100] = { 0 };
	int ID;
	printf("��������Ҫ��ѯ�Ķ���ID\n");
	scanf("%d", &ID);
	itoa(ID, filename, 10);
	strcat(filename, ".txt");
	fp = fopen(filename, "r");//���ļ�
	int borrownum = 0, k = 0, count = 0, m = 0, n = 0;
	char  borrowname[100] = { '\0' }, borrowtime[100] = { '\0' }, return_name[100] = { '\0' };
	char i;
	char cz[100] = { '\0' };
	if ((fp = fopen(filename, "r")) == NULL)//���ļ�
	{
		system("cls");
		printf("\n��¼�ļ�������!�����������");
		getch();
		borrow_message();
	}
	system("cls");
	printf("��ѯ���:\n\n");
	for (; !feof(fp);)
	{
		fscanf(fp, "%s%s", borrowtime, return_name);
		printf("\n\t��������\t����\n");
		printf("\n%-18s%-10s\n", borrowtime, return_name);
		k++;

	}
	if (k == 0)//�ļ���Ϊ��������޼�¼��������һ��
	{
		system("cls");
		printf("\n�޷��ϼ�¼!\n");
		getch();
		borrow_message();
	}
	fclose(fp);//��ѯ����
	getch();
	ReaderFunction();
}


int statistic_book()//ͳ��ͼ���ı�����
{
	FILE* fp;
	int t = 0, n;
	float price = 0;
	char name[100] = { '\0' }, author[100] = { '\0' }, publisher[100] = { '\0' }, kind[100] = { '\0' }, number[100] = { '\0' };
	fp = fopen("library.txt", "r");//���ļ�
	for (n = 0; !feof(fp); n++)//������ļ�
		fscanf(fp, "%s%s%s%s%s%d%f", number, name, author, publisher, kind, &t, &price);
	fclose(fp);//�ر��ļ�
	return (n);//���ظ���
}


int statistic_reader()//ͳ���Ķ��߱���������

{
	FILE* fp;
	int ID_card = 0, n;
	int type;
	char name1[100] = { '\0' }, time[100] = { '\0' }, name2[100] = { '\0' };
	fp = fopen("reader.txt", "r");//���ļ�
	for (n = 0; !feof(fp); n++)//������ļ�
		fscanf(fp, "%d%s%d", &ID_card, &name1, &type);
	n--;
	fclose(fp);//�ر��ļ�
	return (n);//���ظ���
}


int statistic_book3()//ͳ���˺������ı�����
{
	FILE* fp;
	int ID = 0, n;
	char code[100] = { '\0' };
	fp = fopen("land.txt", "r");//���ļ�
	for (n = 0; !feof(fp); n++)//������ļ�
		fscanf(fp, "%d %s", &ID, code);
	n--;
	fclose(fp);//�ر��ļ�
	return (n);//���ظ���
}



void adds()//����ͼ��
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

	if ((fp = fopen("library.txt", "r+")) == NULL)//if��䣺��ͼ����ļ��������ڴ��ļ����½�
	{
		//fp = fopen("library.txt", "r+");
		fclose(fp);
	}
	//fp = fopen("library.txt", "r+");

	printf("\n�밴���¸�ʽ����ͼ����Ϣ:\n��� ���� ���� ������ ��� ������ ����");

	for (; i != 27;)//Ϊ��ʵ������һ�κ�esc�˳�
	{
		printf("������:\n");
		scanf("%s%s%s%s%s%d%f", num, nam, aut, pub, cat, &many, &price);
		int flag = 0;
		fp = fopen("library.txt", "r+");
		for (int n = 0; !feof(fp); n++)//������ļ�
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
			printf("������Ѵ��ڣ����������밴�س������������밴Esc\n");
			i = getch();//��ͣ����i���պ������һ��ָ��
			for (; i != 13 && i != 27;)//��ֻ֤����CR��ESC�����˳�ѭ��,���������ַ����ã���ͣ���򣬰�'CR'������
				i = getch();
			fclose(fp);
			continue;
		}

		fprintf(fp, "%-20s %-20s %-20s %-20s %-20s %-7d %-8.2f\n", num, nam, aut, pub, cat, many, price);
		fclose(fp);
		printf("���������밴�س������������밴Esc\n");
		i = getch();//��ͣ����i���պ������һ��ָ��
		for (; i != 13 && i != 27;)//��ֻ֤����CR��ESC�����˳�ѭ��,���������ַ����ã���ͣ���򣬰�'CR'������
			i = getch();
	}

	fclose(fp);
	printf("\n����ɹ����������������һ��!");
	getch();
	AdministratorBookFunction();//������һ��
}

void removes()//ɾ��ͼ��
{
	int flag = 1;//�жϼ�¼
	struct book* head = NULL;
	struct book* p, * p1 = NULL, * p2 = NULL;
	int tcount = 0, n = 0, j, k;
	float tprice = 0;
	char  tname[100] = { '\0' }, taut[100] = { '\0' }, tcat[100] = { '\0' }, tpub[100] = { '\0' }, tnum[100] = { '\0' };
	char jborrow_name[100] = { '\0' };
	char i;
	FILE* fp;
	if ((fp = fopen("library.txt", "r")) == NULL)//���ļ�
	{
		system("cls");
		printf("\n��¼�ļ�������!�����������");
		getch();
		BookManageFunction();
	}

	else//ʵ��ɾ���Ĺ���
	{
		system("cls");
		printf("\n��������Ҫɾ��������:");//����ɾ��ͼ������
		scanf("%s", jborrow_name);
		printf("\nȷ��ɾ����س���ȡ���밴Esc\n");
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
			if (strcmp(jborrow_name, tname))//�Ƚ����֣�����ͬ���ֵ���Ϣ���Ƶ�����
			{
				n++;//��ͬ����ֵΪ0��ִ��if������ѭ������ͬ��ִ��ֱ�������в�ͬ����������������
				if (n == 1)//��������
				{
					p1 = p2 = (struct book*)malloc(LEN);
					head = p1;
				}
				else
				{
					p2->next = p1;
					p2 = p1;
					p1 = (struct book*)malloc(LEN);//�½�����
				}

				strcpy(p1->num, tnum);//�������
				strcpy(p1->name, tname);//��������
				strcpy(p1->aut, taut);//������������
				strcpy(p1->pub, tpub);//���Ƴ�����
				strcpy(p1->cat, tcat);//�������
				p1->count = tcount;//���Ƹ���
				p1->price = tprice;//���Ƶ���
			}
		}
		if (n == 0)//���ͼ��ֻ��һ������һ��պú�Ҫɾ������ͬ
		{
			head = NULL;
		}
		else//������������ʣ��һ������ռ䣬���Է��
		{
			p2->next = p1;
			p1->next = NULL;
			fclose(fp);
		}
		if (n == j)
			flag = 0;
	}

	fp = fopen("library.txt", "w");//����ļ���ֻд�򿪣�Ȼ��ر�
	fclose(fp);
	fp = fopen("library.txt", "a");//׷���ļ�
	p = head;

	for (; p != NULL;)//���������ݸ��ǵ��ļ�
	{
		fprintf(fp, "%-30s %-30s %-30s %-30s %-30s %-7d %-8.2f\n", p->num, p->name, p->aut, p->pub, p->cat, p->count, p->price);
		p = p->next;
	}
	fclose(fp);
	system("cls");
	if (flag)
		printf("\nɾ���ɹ� \n�������������һ��\n");
	else
		printf("\n���鲻���ڣ��޷�ɾ����\n");
	getch();//������һ��
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

	// ��ͼ����ļ�
	fp = fopen("library.txt", "r");
	if (fp == NULL) {
		printf("�����Ҳ���ͼ����ļ���\n");
		return;
	}

	// ��ȡ�û������������ѯ
	printf("��������š����������߻�������������");
	scanf("%s", query);

	// ��ȡ�ļ��е�ͼ����Ϣ������˫������
	while (fscanf(fp, "%s%s%s%s%s%d%f", current->num, current->name, current->aut, current->pub, current->cat, &current->count, &current->price) != EOF) {
		// Ϊ��ǰ�ڵ�����ڴ�

		// ��鵱ǰͼ���Ƿ���������ѯƥ��
		if (strcmp(query, current->num) == 0 || strcmp(query, current->name) == 0 || strcmp(query, current->aut) == 0 || strcmp(query, current->cat) == 0) {
			// ��ӡƥ���ͼ������
			if (found == 0) {
				printf("\n���������\n\n");
				printf("���\t����   \t����\t������\t���\t�ִ���\t����\n");
			}
			printf("%-8s%-30s%-10s%-30s%-30s%-7d%-8.2f\n", current->num, current->name, current->aut, current->pub, current->cat, current->count, current->price);
			found = 1;
		}

		// ����ǰ�ڵ����˫������
		current->prev = NULL;
		current->next = head;
		if (head != NULL) {
			head->prev = current;
		}
		head = current;
	}
	fclose(fp);

	// ���û���ҵ�ƥ���ͼ�飬���ӡ��Ϣ
	if (!found) {
		printf("\nδ�ҵ�ƥ���¼��\n");
	}
	printf("\n�����������");
	getch();
	BookManageFunction();
}

void visit()//���ͼ��
{
	FILE* fp;
	int n = 0;
	int k = 0, m = 0, count = 0;
	float price = 0;
	char  name[100] = { '\0' }, aut[100] = { '\0' }, cat[100] = { '\0' }, pub[100] = { '\0' }, num[100] = { '\0' };
	char i;
	if ((fp = fopen("library.txt", "r")) == NULL)//���ļ�
	{
		system("cls");
		printf("\n��¼�ļ�������!�����������");
		getch();//����
		BookManageFunction();
	}
	n = statistic_book();
	if (n == 0)
	{
		system("cls");
		printf("\n���κμ�¼!");
	}

	fp = fopen("library.txt", "r");//��ֻ���ļ�
	system("cls");
	printf("���\t����\t����\t\t������\t\t���\t\t�����\t����\n");

	for (m = 0; m < n; m++)//�������
	{
		fscanf(fp, "%s%s%s%s%s%d%f", num, name, aut, pub, cat, &count, &price);
		printf("%-8s%-30s%-30s%-30s%-30s%-7d%-8.2f\n", num, name, aut, pub, cat, count, price);
	}
	fclose(fp);
	printf("\n�����������\n");
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

//������������
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
		printf("�޷����ļ�\n");
		return;
	}

	printf("��ѡ������ʽ��\n1.���������\n2.������������\n");
	scanf(" %c", &sort_option);
	struct BookNode * p1 = NULL, * p2 = NULL;

	int k = statistic_book();//ͳ��ͼ����ļ�����
	int n = 0;
	for (int i = 0; i < k; i++)//�Ƚ�ͼ����Ϣ�����������Ŀ��
	{
		fscanf(fp, "%s%s%s%s%s%d%f", num, name, aut, pub, cat, &count, &price);
		n++;
		if (n == 1)
		{
			p1 = p2 = (struct BookNode*)malloc(sizeof(struct BookNode));//�öδ�����һ�����ļ��ж�ȡ���ݲ���������Ĺ��̡����У�n��������¼��ȡ�����������ı�����

				head = p1;
		}	
		else
		{
			p2->next = p1;
			p2 = p1;
			p1 = (struct BookNode*)malloc(sizeof(struct BookNode));

		}	
		strcpy(p1->num, num);//�������
		strcpy(p1->name, name);//��������
		strcpy(p1->aut, aut);//��������
		strcpy(p1->pub, pub);//���Ƴ�����
		strcpy(p1->cat, cat);//�������
		p1->count = count;//�����ִ���
		p1->price = price;//���Ƶ���
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
	case '1': // ���������
		head=sort_by_num(head);
		break;
	case '2': // ������������
		head=sort_by_aut(head);
		break;
	default:
		printf("�������\n");
		return;
	}

	fp = fopen("library.txt", "w");
	if (fp == NULL) {
		printf("�޷����ļ�\n");
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

	printf("����ɹ���\n");
	getch();
	system("cls");
	BookManageFunction();
}

