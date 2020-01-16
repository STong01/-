#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TXL.h"

struct TXL g_allMen[1000];
int g_count;

int menu()
{
	int tmp, ret;
	printf("\n" 
		"                                 欢迎进入【手机通讯录】\n"
		"\n"
		"                          …………………………………………………\n"
		"                                 ****    手机通讯录   ****\n"
		"                          …………………………………………………\n"
		"\n"
		"                           *  *****************************  *\n"
		"\n"
		"                           >>……1、  添加联系人信息  ……<< *\n"
		"\n" 												   
		"                           >>……2、删除指定联系人信息……<< *\n"
		"\n" 												   
		"                           >>……3、查找指定联系人信息……<< *\n"
		"\n" 												   
		"                           >>……4、修改指定联系人信息……<< *\n"
		"\n" 												  
		"                           >>……5、显示所有联系人信息……<< *\n"
		"\n" 												   
		"                           >>……6、  清空所有联系人  ……<< *\n"
		"\n" 												  
		"                           >>……0、    退出通讯录    ……<< *\n"
		"\n"
		"                           *  *****************************  *\n"
		"                           \n"
		"                           请输入一位数字（1-6）选择您所需的功能，并按回车键确认【退出请输0】:"
		"                           \n");
	ret = scanf("%d", &tmp);
	return ret ? tmp : -1;
}

void TXL()
{
	int cd;
	int ret;
	char str[256] = { 0 };
	int searchRes[1001] = { 0 };
	do
	{
		cd = menu();
		system("cls");
		switch (cd)
		{
		case ADD_MEN:
			inputData();
			break;

		case DELETE_MEN:
			printf("请输入你要删除的用户：\n");
			memset(str, 0, sizeof(str));
			scanf("%s", str);
			ret = catchOneData(str);
			if (ret > 0)
			{
				deleteOneData(ret);
				printf("删除成功\n");
			}
			else
			{
				printf("删除失败\n");
			}
			break;

		case SEARCH_MEN:
			printf("请输入你要检索的信息：\n");
			memset(str, 0, sizeof(str));
			memset(searchRes, 0, sizeof(searchRes));
			scanf("%s", str);
			searchData(str, searchRes);
			outputSearchData(searchRes);
			printf("共找到%d条数据\n", searchRes[0]);
			break;

		case CHANGE_MEN:
			printf("请输入你要修改的学生姓名：");
			memset(str, 0, sizeof(str));
			scanf("%49s", str);
			changeDate(str);
			break;

		case DISPLAY_MEN:
			outputData();
			break;

		case EMPTY_MEN:
			memset(g_allMen, 0, g_count * sizeof(struct TXL));
			g_count = 0;
			printf("操作完成\n");
			break;

		case -1:
			printf("输入有误，请重新输入\n");
			break;

		default:
			printf("输入有误，请重新输入\n");
		}
	} while (cd != 0);
}

int main()
{
	TXL();
	return 0;
}