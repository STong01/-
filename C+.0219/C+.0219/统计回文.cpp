#include <iostream>
#include <string>
using namespace std;

//统计回文
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
		string s = s1;//重新定义新的s1进行回文判断，若直接在s1中进行插入，会影响之后的插入判断
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