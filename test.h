#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED


#define LEN sizeof(struct book)//有关图书信息的结构体
#define LEN1 sizeof(struct reader)//有关读者信息的结构体
#define LEN2 sizeof(struct land)//有关登录系统的结构体
#define LEN3 sizeof(struct administrator)


enum ReaderType { UNDERGRADUATE, POSTGRUADUATE, PHDSTUDENT, TEACHER};
extern int ReaderID;
struct book//图书信息
{
	char num[100], name[100], aut[100], pub[100], cat[100];     //pub-出版社     cat-目录
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
struct reader//读者借阅信息
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
struct land//登录信息
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
//单歆
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



//林晓彤
void search();//查询图书
void adds();//增加图书
void removes();//删除图书
void visit();//浏览图书
int statistic_book();//统计library文本个数函数
void vague();
void search();//查询图书
void sort();


//李景怡
void borrow_message();//读者借阅信息
void borrow( );//借书
void inquire();//管理员查询借书
void visit_borrow();// 浏览借书情况
int statistic_reader();//统计文读者本个数函数
int statistic_book3();//统计账号密码文本个数
void visit_borrow();//显示借书情况函数


//李锐哲
void alter(int, char[]);  //修改函数
void land();//登录功能系统
void create();//创建账号密码
void altercode();//修改密码
void AdministratorLandMain();
void AdministratorAlterCode();
int matchAdministrator(int m, char a[100]);
void AdministratorAlter(int z, char m[100]);//修改函数
int AdministratorCount();
void AdministratorLand();
int match(int m, char a[100]);//匹配数据库中的账号密码

#endif // TEST_H_INCLUDED
#pragma once
