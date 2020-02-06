#include <iostream>
#include <vector>
using namespace std;

#if 0
//长按键入
//你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
//
//你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
//
//示例 1：
//输入：name = "alex", typed = "aaleex"
//输出：true
//解释：'alex' 中的 'a' 和 'e' 被长按。

class Solution {
public:
	bool isLongPressedName(string name, string typed) 
	{
		int l_n = name.length();
		int l_t = typed.length();
		if (l_t < l_n)
			return false;

		int i = 0;
		int j = 0;
		while (i < l_n)
		{
			if (name[i] == typed[j])
			{
				i++;
				j++;
			}
			else if (j>0 && typed[j] == typed[j - 1])
			{
				j++;
			}
			else
				return false;
		}
		return true;
	}
};
#endif

#if 0
//有序数组的平方
//给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

//示例 1：
//输入：[-4, -1, 0, 3, 10]
//输出：[0, 1, 9, 16, 100]

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) 
	{
		vector<int> B ;
		for (int i = 0; i < A.size(); i++)
		{
			int val = A[i] * A[i];
			B.push_back(val);
		}

		for (int i = 0; i < B.size() - 1; i++)
		{
			for (int j = 0; j < B.size() - 1 - i; j++)
			{
				if (B[j] > B[j + 1])
				{
					int tmp = B[j];
					B[j] = B[j + 1];
					B[j + 1] = tmp;
				}
			}
		}
		return B;
	}
};
#endif

#if 0
//仅仅反转字母
//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
//
//示例 1：
//输入："ab-cd"
//输出："dc-ba"

class Solution {
public:
	string reverseOnlyLetters(string S) 
	{
		int i = 0;
		int j = S.size() - 1;
		while (i < j)
		{
			while (S[i] < 'A' || (S[i] < 'Z' && S[i] > 'a') || S[i] > 'z')
			{
				i++;
			}
			while (S[i] < 'A' || (S[i] < 'Z' && S[i] > 'a') || S[i] > 'z')
			{
				j--;
			}
			if (i < j)
				swap(S[i], S[j]);
		}
		return S;
	}
};
#endif

int main()
{
	char str[] = "ABCD", *p = str; 
	printf("%d\n", *(p + 4));
	system("pause");
	return 0;
}