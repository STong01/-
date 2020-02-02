#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#if 0
//给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。
//如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
//如果不存在最后一个单词，请返回 0 。
//说明：一个单词是指仅由字母组成、不包含任何空格的 最大子字符串。

//示例 :
//输入 : "Hello World"
//输出 : 5

class Solution {
public:
	int lengthOfLastWord(string s) 
	{
		int tmp = 0;
		int sum = 0;
		if (s.size() == 0)
		{
			return 0;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != ' ')
			{
				tmp++;
				sum = tmp;
			}
			else
			{
				tmp = 0;
			}
		}
		return sum;
	}
};

#endif

#if 0
//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//说明 :
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//示例 :
//输入 :
//	nums1 = [1, 2, 3, 0, 0, 0], m = 3
//	nums2 = [2, 5, 6], n = 3
//输出 : [1, 2, 2, 3, 5, 6]

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
	{
		for (int i = m; i < m + n; i++)
		{
			nums1[i] = nums2[i - m];
		}
		
		for (int i = 0; i < m + n; i++)
		{
			for (int j = 0; j < m + n - i - 1; j++)
			{
				if (nums1[j] > nums1[j + 1])
				{
					int tmp = nums1[j];
					nums1[j] = nums1[j + 1];
					nums1[j + 1] = tmp;
				}
			}
		}
	}
};
#endif

int func(int a) 
{ 
	int b; 
	switch (a)
	{ 
	case 1: b = 30; 
	case 2: b = 20; 
	case 3: b = 16; 
	default: b = 0; 
	}
	return b; 
}

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) 
	{
		if (nums.size() == 0)
			return false;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == nums[i + 1])
					return true;
		}
		return false;
	}
};

int main()
{
	int p = func(1);
	cout << p << endl;

	system("pause");
	return 0;
}