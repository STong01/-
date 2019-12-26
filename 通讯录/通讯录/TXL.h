#ifndef _TXL_H
#define _TXL_H

enum{
	ADD_MEN = 1,//���
	DELETE_MEN, //ɾ��
	SEARCH_MEN, //����
	CHANGE_MEN, //�޸�
	DISPLAY_MEN,//��ʾ
	EMPTY_MEN   //���
};

extern struct TXL g_allMen[1000];
extern int g_count; 

struct TXL
{
	char name[50];   //����
	char gender;     //�Ա�
	char telnum[30]; //�绰����
	char addr[200];  //��ַ
	int age;         //����
};

void inputData();                                 
void outputData();                                
void searchData(char * find, int * searchres);    
void changeDate(char * name);                     
void outputSearchData(int * data);                
int catchOneData(char *find);                     
void deleteOneData(int n);                        

#endif /* _TXL_H */