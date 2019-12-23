#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "TXL.h"

void inputData()// �������
{
	struct TXL tmp;

	printf("������������\n");
	scanf("%49s", tmp.name);
	getchar();

	printf("�������Ա�f/m����\n");
	scanf("%c", &tmp.gender);

	printf("���������䣺\n");
	scanf("%d", &tmp.age);

	printf("������绰���룺\n");
	scanf("%29s", tmp.telnum);

	printf("�������ַ��\n");
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

void searchData(char * find, int * searchres)//��������
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

void outputSearchData(int * data)//�������
{
	int i;
	if (data[0] == 0)
	{
		printf("û�з�������������\n");
		return;
	}

	printf("     ����     �Ա� ����     �绰      סַ\n");
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

int catchOneData(char *find)//ɾ������
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
		printf("��������Ҫɾ���ڼ�������:\n");
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
		printf("�Բ���û����Ҫ�޸ĵ��û�\n");
	}
	else
	{
		printf("�������޸ĺ��������\n");
		scanf("%49s", g_allMen[i].name);
		getchar();

		printf("�������޸ĺ���Ա�f/m����\n");
		scanf("%c", &g_allMen[i].gender);

		printf("�������޸ĺ�����䣺\n");
		scanf("%d", &g_allMen[i].age);

		printf("�������޸ĺ�ĵ绰���룺\n");
		scanf("%29s", g_allMen[i].telnum);

		printf("�������޸ĺ�ĵ�ַ��\n");
		scanf("%199s", g_allMen[i].addr);
	}
	getchar();
}

void outputData()//�������
{
	int i;
	if (g_count == 0)
	{
		printf("û������\n");
		return;
	}

	printf("  ����     �Ա� ����     �绰        סַ\n");
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

void deleteOneData(int n)//���ͨѶ¼
{
	int i;
	for (i = n; i < g_count; i++)
	{
		g_allMen[i] = g_allMen[i + 1];
	}
	g_count--;
}

