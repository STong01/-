#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;//�����ַ�����s1Ϊ�����ַ�����s2Ϊ�����ַ���
	getline(cin, s1);//�����ַ���
	getline(cin, s2);

	int p1[256] = { 0 };//��¼�����ַ���
	for (size_t i = 0; i < s2.size(); i++)
	{
		p1[s2[i]] += 1;
	}

	string ret;//����ɾ������ַ���
	for (size_t i = 0; i < s1.size(); i++)
	{
		if (p1[s1[i]] == 0)
		{
			ret += s1[i];
		}
	}

	cout << ret << endl;

	return 0;
}