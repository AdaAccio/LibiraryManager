#include <stdio.h>
#include <stdlib.h>//���а���system����
#include <conio.h>//������ͨ������̨���� �������� ����������ĺ�������getch������
#include <string.h>//�����ַ�����
#include <math.h>
#include <assert.h>
extern int ReaderID;
#define LEN sizeof(struct book)//�й�ͼ����Ϣ�Ľṹ��
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

				printf("��������밴�������������");
				getch();
				AdministratorLand();
			}
			}
		}
	}
	printf("��������밴�������������");
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
	fp = fopen("Administrator.txt", "r");//���ļ�
	for (n = 0; !feof(fp); n++)//������ļ�
		fscanf(fp, "%d %s", &ID, code);
	n--;
	fclose(fp);//�ر��ļ�
	return n;//���ظ���
}
int matchAdministrator(int m, char a[100])
{
	FILE* fp;
	int n = 0, i = 0;
	int ID_card;
	char password[100];

	if ((fp = fopen("Administrator.txt", "r")) == NULL)//�����ڹ���Ա�ļ�
	{
		system("cls");
		printf("\n ��δ�����û�!���½��˻�");
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
	printf("\n\n\t    ��ӭʹ�ù���Ա��¼ϵͳ\n\n");
	printf("**********************************************");
	printf("\n\n\t\t1.��¼����Աϵͳ\n\n");
	printf("\n\n\t\t2.�޸�����\n\n");
	printf("\n\n\t\t3.�˳�ϵͳ\n\n");
	printf("\n\n\t    �밴��ѡ�񣬻س�ȷ��\n");
	printf("**********************************************");
}
void AdministratorAlter(int z, char m[100])//�޸ĺ���
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
		if (z != ID_card1)//�Ƚ����֣�����ͬ���ֵ���Ϣ���Ƶ�����
		{
			n++;//��ͬ����ֵΪ0��ִ��if������ѭ������ͬ��ִ��ֱ�������в�ͬ����������������
			if (n == 1)//��������
			{
				p1 = p2 = (struct administrator*)malloc(LEN3);
				head = p1;
			}
			else
			{
				p2->next = p1;
				p2 = p1;
				p1 = (struct administrator*)malloc(LEN3);//�½�����
			}
			p1->ID = ID_card1;
			strcpy(p1->password, mima1);//�����˺�����
		}
	}
	if (n == 0)
	{
		head = NULL;
	}
	else//������������ʣ��һ������ռ䣬���Է��
	{
		p2->next = p1;
		p1->next = NULL;
		fclose(fp);
	}
	fp = fopen("Administrator.txt", "w");//����ļ���ֻд�򿪣�Ȼ��ر�
	fclose(fp);
	fp = fopen("Administrator.txt", "a");//׷���ļ�
	p = head;
	for (; p != NULL;)//���������ݸ��ǵ��ļ�
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

	if ((fp = fopen("Administrator.txt", "r")) == NULL)//���ļ�
	{
		system("cls");
		printf("\n��¼�ļ�������!�����������");
		getch();
		system("cls");
		AdministratorLand();
	}
	system("cls");
	printf("����������ʺź;����룺\n");
	scanf("%d %s", &inputID, inputPassword);
	m = AdministratorCount();
	for (n = 0; n <= m; n++)
	{
		fscanf(fp, "%d %s", &ID, password);
		if (ID == inputID)
		{
			if (!strcmp(password, inputPassword))
			{
				printf("�������µ�����");
				scanf("%s", password0);
				printf("�ٴ���������:\n");
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
					printf("�����������벻һ��,��������˳�");
					hit = getch();
					system("cls");
					AdministratorLand();

				}
			}
			else
			{
				printf("��������󣬰���������أ�");
				getch();
				system("cls");
				AdministratorLand();

			}

		}
	}
	printf("�����ڴ��˺ţ������������");
	fclose(fp);//�޸Ľ���
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
		printf("\n�������˺�:\n");
		scanf("%d", &ID_card);
		printf("ȷ�������밲�س������������밴ECS");
		hit = getch();//��ͣ����i���պ������һ��ָ��
		for (; hit != 13 && hit != 27;)//��ֻ֤����CR��ESC�����˳�ѭ��,���������ַ����ã���ͣ���򣬰�'CR'������
		{
			hit = getch();
		}
	} while (hit == 27);
	printf("\n����������:\n");
	scanf("%s", password);
	i = matchAdministrator(ID_card, password);
	if (i == 1)
	{
		printf("��½�ɹ�!�����������");
		getch();
		system("cls");
		AdministratorFunction();
	}
	else
	{
		if (i == -1)
		{
			printf("�������!");
			getch();
			AdministratorLand();
		}
		if (i == 0)
			printf("�����ڴ��û�");
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

				printf("��������밴�������������");
				getch();
				AdministratorLand();
			}
			}
		}
	}
	printf("��������밴�������������");
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
		printf("�޷����ļ�\n");
		return;
	}

	printf("���������ID��\n");
	scanf("%d", &inputID);

	if (feof(fp) != 0) {
		printf("���޶�����Ϣ\n");
	}
	else {
		printf("��������Ҫ�޸ĵ���Ϣ��\n1.����\n2.��������\n");
		int index;
		scanf("%d", &index);

		switch (index) {
		case 1:
			printf("��������������\n");
			scanf("%s", NewName);
			//NewType = type;
			break;
		case 2:
			printf("������������(0-3)��\n");
			scanf("%d", &NewType);
			//strcpy(NewName, name);
			break;
		default:
			printf("�������\n");
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
			printf("���˺Ų����ڣ�����������\n");
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

	printf("�޸ĳɹ���\n");
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
	printf("����������Ҫ���ҵ��˺ţ�\n");
	int inputID;
	scanf("%d", &inputID);
	if (feof(fp) != 0)
	{
		printf("���޶�����Ϣ\n");
	}
	while (feof(fp) == 0)
	{
		int ID, type;
		char name[100] = { 0 };
		fscanf(fp,"%d %s %d", &ID, name, &type);
		if (inputID == ID)
		{
			flag++;
			printf("�ö��ߵ���Ϣ���£�\n������%s\n���ͣ�", name);
			if (type == 0)
			{
				printf("������\n");
				break;
			}
			else if (type == 1)
			{
				printf("�о���\n");
				break;
			}
			else if (type == 2)
			{
				printf("��ʿ��\n");
				break;
			}
			else if (type == 3)
			{
				printf("��ְ��\n");
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
		printf("δ��ѯ���ö���");
	}
	printf("�������������һ��");
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
	printf("��������ӵĶ����˺ţ�\n");
	scanf("%d", &addID);
	itoa(addID, filename, 10);

	printf("���������Ĭ�����룺\n");
	scanf("%s", addPassword);
	printf("���������������\n");
	char name[100] = { 0 };
	scanf("%s", name);
	//fprintf("%d %s", addID, addPassword);
	printf("��ѡ��������ͣ�\n");
	printf("0��������\n");
	printf("1���о���\n");
	printf("2����ʿ��\n");
	printf("3����ְԱ��\n");
	int type;
	strcat(filename, ".txt");
	scanf("%d", &type);
	FILE* fp1 = fopen(filename, "r");
	FILE* fp2, * fp3;
	if (fp1 != NULL)
	{
		printf("�ö����Ѵ���\n");
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
		printf("����%d¼��ɹ�\n", addID);

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
		printf("�޷����ļ�\n");
		return;
	}

	printf("���������ID��\n");
	scanf("%d", &inputID);

	if (feof(fp) != 0) {
		printf("���޶�����Ϣ\n");
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
			printf("δ�ҵ�ƥ��Ķ���ID\n");
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
			printf("ɾ���ɹ���\n");
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
	AdministratorBookFunction();
}
void AdministratorVisitBook()//���ͼ��
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
	AdministratorBookFunction();
}