#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s;//定义字符串

	getline(cin, s);//输入字符串，不能使用cin，cin碰见空格则会停止输入

	reverse(s.begin(), s.end());//倒置整体字符串

	auto start = s.begin();

	while (start != s.end())
	{

		auto end = start;

		while (end != s.end() && *end != ' ')//查找字符串中的单个字符
		{
			end++;
		}

		reverse(start, end);//将单词倒置

		if (end != s.end())//转移到下一个未倒置单词
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