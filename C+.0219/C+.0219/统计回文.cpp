#include <iostream>
#include <string>
using namespace std;

//ͳ�ƻ���
bool isH_W(string& s)
{
	size_t begin = 0;
	size_t end = s.size() - 1;

	while (begin < end)
	{
		if (s[begin] != s[end])
		{
			return false;
		}

		begin++;
		end--;
	}
	return true;
}

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	size_t sum;

	for (size_t i = 0; i <= s1.size(); i++)
	{
		string s = s1;//���¶����µ�s1���л����жϣ���ֱ����s1�н��в��룬��Ӱ��֮��Ĳ����ж�
		s.insert(i, s2);
		if (isH_W(s))
		{
			sum++;
		}
	}

	cout << sum << endl;

	system("pause");
	return 0;
}