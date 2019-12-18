#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, res, cur;

	while (cin >> s1)//输入字符串
	{
		int max = 0;//保存字符串长度

		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] >= '0' && s1[i] <= '9')//判断字符类型
			{
				cur += s1[i];//保存满足字符类型的字符
				while (s1[i + 1] >= '0' && s1[i + 1] <= '9')
				{
					i++;
					cur += s1[i];
				}

				if (cur.size() > max)//判断字符串长度是否最长
				{
					max = cur.size();
					res = cur;
				}
				else if (cur.size() == max)
				{
					res += cur;
				}
			}
			cur.clear();//清空临时存取字符的字符串
		}
		cout << res << "," << max << endl;
	}

	system("pause");
	return 0;
}