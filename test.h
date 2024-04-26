#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED


#define LEN sizeof(struct book)//�й�ͼ����Ϣ�Ľṹ��
#define LEN1 sizeof(struct reader)//�йض�����Ϣ�Ľṹ��
#define LEN2 sizeof(struct land)//�йص�¼ϵͳ�Ľṹ��
#define LEN3 sizeof(struct administrator)


enum ReaderType { UNDERGRADUATE, POSTGRUADUATE, PHDSTUDENT, TEACHER};
extern int ReaderID;
struct book//ͼ����Ϣ
{
	char num[100], name[100], aut[100], pub[100], cat[100];     //pub-������     cat-Ŀ¼
	int  count;
	float price;
	struct book* next;
};
struct administrator
{
	int ID;
	char password[100];
	struct administrator* next;
};
struct reader//���߽�����Ϣ
{
	int ID_card;
	char borrow_name[100], time[100], return_name[100];
	enum ReaderType type;
	int BookNumber;

	//
	char name[100];
	struct reader* prev;
	struct reader* next;
};
struct land//��¼��Ϣ
{
	int ID_card;
	char password[100];
	struct land* next;
};
struct BookNode {
	char num[100];
	char name[100];
	char aut[100];
	char pub[100];
	char cat[100];
	int count;
	float price;
	struct BookNode* prev;
	struct BookNode* next;
};
//���
void ReaderMainMenu();
void BookMenu();
void BorrowMenu();
void ReaderLandMenu();
void ReaderMainFunction();
void BookManageFunction();
void ReaderLandMain();
void ReaderDelete();
void ReturnBook();
void AdministratorBookSearch();
void ReaderManagerMenu();
void ReaderFunction();
void ReaderProfileChange();
void AddReader();
void ReaderSearch();
void AdministratorMenu();
void AdministratorFunction();
void WelcomeMenu();
void WelcomeFunction();
void SortMenu();
void AdministratorLandMenu();
void AdministratorVisitBook();



//����ͮ
void search();//��ѯͼ��
void adds();//����ͼ��
void removes();//ɾ��ͼ��
void visit();//���ͼ��
int statistic_book();//ͳ��library�ı���������
void vague();
void search();//��ѯͼ��
void sort();


//���
void borrow_message();//���߽�����Ϣ
void borrow( );//����
void inquire();//����Ա��ѯ����
void visit_borrow();// ����������
int statistic_reader();//ͳ���Ķ��߱���������
int statistic_book3();//ͳ���˺������ı�����
void visit_borrow();//��ʾ�����������


//������
void alter(int, char[]);  //�޸ĺ���
void land();//��¼����ϵͳ
void create();//�����˺�����
void altercode();//�޸�����
void AdministratorLandMain();
void AdministratorAlterCode();
int matchAdministrator(int m, char a[100]);
void AdministratorAlter(int z, char m[100]);//�޸ĺ���
int AdministratorCount();
void AdministratorLand();
int match(int m, char a[100]);//ƥ�����ݿ��е��˺�����

#endif // TEST_H_INCLUDED
#pragma once
