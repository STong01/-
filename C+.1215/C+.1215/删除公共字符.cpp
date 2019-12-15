#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;//定义字符串，s1为输入字符串，s2为检验字符串
	getline(cin, s1);//输入字符串
	getline(cin, s2);

	int p1[256] = { 0 };//记录检验字符串
	for (size_t i = 0; i < s2.size(); i++)
	{
		p1[s2[i]] += 1;
	}

	string ret;//保存删除后的字符串
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