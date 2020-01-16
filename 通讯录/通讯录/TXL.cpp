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
		"                                 ��ӭ���롾�ֻ�ͨѶ¼��\n"
		"\n"
		"                          ��������������������������������������\n"
		"                                 ****    �ֻ�ͨѶ¼   ****\n"
		"                          ��������������������������������������\n"
		"\n"
		"                           *  *****************************  *\n"
		"\n"
		"                           >>����1��  �����ϵ����Ϣ  ����<< *\n"
		"\n" 												   
		"                           >>����2��ɾ��ָ����ϵ����Ϣ����<< *\n"
		"\n" 												   
		"                           >>����3������ָ����ϵ����Ϣ����<< *\n"
		"\n" 												   
		"                           >>����4���޸�ָ����ϵ����Ϣ����<< *\n"
		"\n" 												  
		"                           >>����5����ʾ������ϵ����Ϣ����<< *\n"
		"\n" 												   
		"                           >>����6��  ���������ϵ��  ����<< *\n"
		"\n" 												  
		"                           >>����0��    �˳�ͨѶ¼    ����<< *\n"
		"\n"
		"                           *  *****************************  *\n"
		"                           \n"
		"                           ������һλ���֣�1-6��ѡ��������Ĺ��ܣ������س���ȷ�ϡ��˳�����0��:"
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
			printf("��������Ҫɾ�����û���\n");
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
			printf("��������Ҫ��������Ϣ��\n");
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
			printf("�������\n");
			break;

		case -1:
			printf("������������������\n");
			break;

		default:
			printf("������������������\n");
		}
	} while (cd != 0);
}

int main()
{
	TXL();
	return 0;
}