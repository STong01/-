#ifndef _TXL_H
#define _TXL_H

enum{
	ADD_MEN = 1,//添加
	DELETE_MEN, //删除
	SEARCH_MEN, //查找
	CHANGE_MEN, //修改
	DISPLAY_MEN,//显示
	EMPTY_MEN   //清空
};

extern struct TXL g_allMen[1000];
extern int g_count; 

struct TXL
{
	char name[50];   //姓名
	char gender;     //性别
	char telnum[30]; //电话号码
	char addr[200];  //地址
	int age;         //年龄
};

void inputData();                                 //输入数据
void outputData();                                //输出数据
void searchData(char * find, int * searchres);    //查找数据
void changeDate(char * name);                     //修改数据
void outputSearchData(int * data);                //输出查找
int catchOneData(char *find);                     //删除数据
void deleteOneData(int n);                        //清空通讯录

#endif /* _TXL_H */