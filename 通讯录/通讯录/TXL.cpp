#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "TXL.h"

struct TXL g_allMen[1000];
int g_count;

int menu()
{
	int tmp, ret;
	printf("\n"
		"*  ********************  *\n"
		"*  1.  添加联系人信息    *\n"
		"*  2.删除指定联系人信息  *\n"
		"*  3.查找指定联系人信息  *\n"
		"*  4.修改指定联系人信息  *\n"
		"*  5.显示所有联系人信息  *\n"
		"*  6.  清空所有联系人    *\n"
		"*  ********************  *\n"
		"\n"
		"请输入选项："
		"\n");
	ret = scanf("%d", &tmp);
	return ret ? tmp : -1;
}

void TXL()
{
	int cd;
	int ret;
	char str[256] = { 0 };
	int searchRes[1001] = { 0 };
	while (1)
	{
		cd = menu();
		switch (cd)
		{
		case ADD_MEN:
			inputData();
			break;

		case DELETE_MEN:
			printf("请输入你要删除的条目：\n");
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
			printf("请输入你要检索的字符串：\n");
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
			break;

		case -1:
			printf("输入有误，请重新输入\n");
			break;

		default:
			printf("输入有误，请重新输入\n");
		}
	}
}

int main()
{
	TXL();
	return 0;
}