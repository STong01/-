#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
using namespace std;

//验证回文串
#if 0
//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。
//示例 1:
//输入 : "A man, a plan, a canal: Panama"
//输出 : true

class Solution {
public:
	bool isPalindrome(string s) 
	{
		string str = "";
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				s[i] -= 32;
			}
			if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
			{
				str += s[i];
			}
		}

		int i = 0;
		int j = str.length() - 1;
		while (i < j)
		{
			if (str[i] != str[j])
			{
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
};
#endif

//压缩字符串
#if 0
//给定一组字符，使用原地算法将其压缩。
//压缩后的长度必须始终小于或等于原数组长度。
//数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
//在完成原地修改输入数组后，返回数组的新长度。
//
//示例 1：
//输入：
//["a", "a", "b", "b", "c", "c", "c"]
//输出：
//返回6，输入数组的前6个字符应该是：["a", "2", "b", "2", "c", "3"]
//说明：
//"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。

class Solution {
public:
	int compress(vector<char>& chars) 
	{
		int n = chars.size();
		int i = 0;
		int sum = 0;
		while (i < n)
		{
			int j = i + 1;
			while (j < n && chars[j] == chars[i])
				j++;

			chars[sum++] = chars[i];

			int tmp = j - i;
			if (tmp > 1){
				stack<char> st;
				while (tmp)
				{
					st.push(tmp % 10 + '0');
					tmp /= 10;
				}
				while (!st.empty())
				{
					chars[sum++] = st.top();
					st.pop();
				}
			}
			i = j;
		}
		return sum;
	}
};
#endif

//最短无序连续子数组
#if 0
//给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
//你找到的子数组应是最短的，请输出它的长度。
//示例 1:
//输入 : [2, 6, 4, 8, 10, 9, 15]
//输出 : 5
//解释 : 你只需要对[6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) 
	{
		const int len = nums.size();
		vector<int> copy = nums;
		sort(copy.begin(), copy.end());

		int l = 0, r = len - 1;
		while (l<len && copy[l] == nums[l])
			l++;
		while (r >= l && copy[r] == nums[r])
			r--;
		return r - l + 1;
	}
};
#endif

//逆波兰表达式求值
#if 0
//根据逆波兰表示法，求表达式的值。
//
//有效的运算符包括  + , -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//
//说明：
//
//示例 1：
//输入 : ["2", "1", "+", "3", "*"] 
//输出 : 9
//解释 : ((2 + 1) * 3) = 9
class Solution {
public:
	bool panduan(string s)
	{
		if (s == "+" || s == "-" || s == "*" || s == "/")
			return true;

		return false;
	}
	int evalRPN(vector<string>& tokens) 
	{
		int a;
		int b;
		stack<int>s;
		for (auto i = tokens.begin(); i != tokens.end(); i++)
		{
			if (!panduan(*i))
			{
				s.push(stoi(*i));
			}
			else
			{
				a = s.top();
				s.pop();
				b = s.top();
				s.pop();
				if (*i == "+")
					s.push(b + a);

				else if (*i == "-")
					s.push(b - a);

				else if (*i == "*")
					s.push(b * a);

				else if (*i == "/")
					s.push(b / a);
			}
		}
		return s.top();
	}
};
#endif


int func(int i, int j) 
{ 
	if (i <= 0 || j <= 0)
		return 1; 
	return 2 * func(i - 3, j / 2); 
}

int main()
{

	system("pause");
	return 0;
}