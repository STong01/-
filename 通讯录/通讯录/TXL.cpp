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
		"*  1.  �����ϵ����Ϣ    *\n"
		"*  2.ɾ��ָ����ϵ����Ϣ  *\n"
		"*  3.����ָ����ϵ����Ϣ  *\n"
		"*  4.�޸�ָ����ϵ����Ϣ  *\n"
		"*  5.��ʾ������ϵ����Ϣ  *\n"
		"*  6.  ���������ϵ��    *\n"
		"*  ********************  *\n"
		"\n"
		"������ѡ�"
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
			printf("��������Ҫɾ������Ŀ��\n");
			memset(str, 0, sizeof(str));
			scanf("%s", str);
			ret = catchOneData(str);
			if (ret > 0)
			{
				deleteOneData(ret);
				printf("ɾ���ɹ�\n");
			}
			else
			{
				printf("ɾ��ʧ��\n");
			}
			break;

		case SEARCH_MEN:
			printf("��������Ҫ�������ַ�����\n");
			memset(str, 0, sizeof(str));
			memset(searchRes, 0, sizeof(searchRes));
			scanf("%s", str);
			searchData(str, searchRes);
			outputSearchData(searchRes);
			printf("���ҵ�%d������\n", searchRes[0]);
			break;

		case CHANGE_MEN:
			printf("��������Ҫ�޸ĵ�ѧ��������");
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
			printf("������������������\n");
			break;

		default:
			printf("������������������\n");
		}
	}
}

int main()
{
	TXL();
	return 0;
}