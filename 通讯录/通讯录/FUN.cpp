#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "TXL.h"

void inputData()// 添加数据
{
	struct TXL tmp;

	printf("请输入姓名：\n");
	scanf("%49s", tmp.name);
	getchar();

	printf("请输入性别（f/m）：\n");
	scanf("%c", &tmp.gender);

	printf("请输入年龄：\n");
	scanf("%d", &tmp.age);

	printf("请输入电话号码：\n");
	scanf("%29s", tmp.telnum);

	printf("请输入地址：\n");
	scanf("%199s", tmp.addr);

	int i;
	for (i = 0; i < g_count; i++)
	{
		if (strcmp(g_allMen[i].name, tmp.name) > 0)
		{
			break;
		}
	}
	int j;
	for (j = g_count; j > i; j--)
	{
		g_allMen[j] = g_allMen[j - 1];
	}
	g_allMen[i] = tmp;

	g_count++;
}

void searchData(char * find, int * searchres)//查找数据
{
	int i, flag;
	char age[4] = { 0 };
	char * ret;
	for (i = 0; i < g_count; i++)
	{
		do{
			flag = 1;
			ret = strstr(g_allMen[i].name, find);
			if (ret)
			{
				break;
			}

			ret = strstr(g_allMen[i].telnum, find);
			if (ret)
			{
				break;
			}

			sprintf(age, "%d", g_allMen[i].age);
			if (!strcmp(age, find))
			{
				break;
			}

			ret = strstr(g_allMen[i].addr, find);
			if (ret)
			{
				break;
			}

			flag = 0;
		} while (0);

		if (flag)
		{
			searchres[0]++;
			searchres[searchres[0]] = i;
		}
	}
}

void outputSearchData(int * data)//输出查找
{
	int i;
	if (data[0] == 0)
	{
		printf("没有符合条件的数据\n");
		return;
	}

	printf("     姓名     性别 年龄     电话      住址\n");
	for (i = 1; i <= data[0]; i++)
	{
		printf("%2d %-10s %3c  %3d  %11s %s\n",
			i,
			g_allMen[data[i]].name,
			g_allMen[data[i]].gender,
			g_allMen[data[i]].age,
			g_allMen[data[i]].telnum,
			g_allMen[data[i]].addr);
	}
}

int catchOneData(char *find)//删除数据
{
	int schres[1001] = { 0 };
	searchData(find, schres);
	if (schres[0] == 0)
	{
		return -1;
	}
	else if (schres[0] == 1)
	{
		return schres[1];
	}
	else
	{
		int i;
		outputSearchData(schres);
		printf("请输入你要删除第几条数据:\n");
		scanf("%d", &i);
		if (i < 1 || i > schres[0])
		{
			return -1;
		}
		return schres[i];
	}
}

void changeDate(char * name)
{
	int tmp = 0;
	int i, j;

	for (j = 0; j < g_count; j++)
	{
		if (g_allMen[j].name == name)
		{
			i = j;
			tmp = 1;
			break;
		}
	}

	if (tmp == 0)
	{
		printf("对不起，没有您要修改的用户\n");
	}
	else
	{
		printf("请输入修改后的姓名：\n");
		scanf("%49s", g_allMen[i].name);
		getchar();

		printf("请输入修改后的性别（f/m）：\n");
		scanf("%c", &g_allMen[i].gender);

		printf("请输入修改后的年龄：\n");
		scanf("%d", &g_allMen[i].age);

		printf("请输入修改后的电话号码：\n");
		scanf("%29s", g_allMen[i].telnum);

		printf("请输入修改后的地址：\n");
		scanf("%199s", g_allMen[i].addr);
	}
	getchar();
}

void outputData()//输出数据
{
	int i;
	if (g_count == 0)
	{
		printf("没有数据\n");
		return;
	}

	printf("  姓名     性别 年龄     电话        住址\n");
	for (i = 0; i < g_count; i++)
	{
		printf("%-10s %3c  %3d  %11s %s\n",
			g_allMen[i].name,
			g_allMen[i].gender,
			g_allMen[i].age,
			g_allMen[i].telnum,
			g_allMen[i].addr);
	}
}

void deleteOneData(int n)//清空通讯录
{
	int i;
	for (i = n; i < g_count; i++)
	{
		g_allMen[i] = g_allMen[i + 1];
	}
	g_count--;
}

