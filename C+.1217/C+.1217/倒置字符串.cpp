#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s;//�����ַ���

	getline(cin, s);//�����ַ���������ʹ��cin��cin�����ո����ֹͣ����

	reverse(s.begin(), s.end());//���������ַ���

	auto start = s.begin();

	while (start != s.end())
	{

		auto end = start;

		while (end != s.end() && *end != ' ')//�����ַ����еĵ����ַ�
		{
			end++;
		}

		reverse(start, end);//�����ʵ���

		if (end != s.end())//ת�Ƶ���һ��δ���õ���
		{
			start = end + 1;
		}
		else
		{
			start = end;
		}
	}

	cout << s << endl;

	system("pause");
	return 0;
}