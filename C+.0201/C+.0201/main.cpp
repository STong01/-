#include <iostream>
#include <vector>
using namespace std;

#if 0
//移除元素
//给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

//示例 1:
//给定 nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2,

//函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

//注意这五个元素可为任意顺序。

//你不需要考虑数组中超出新长度后面的元素。
class Solution {
public:
	int removeElement(vector<int>& nums, int val) 
	{
		int tmp = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
			{
				nums[tmp] = nums[i];
				tmp++;
			}
		}
		return tmp;
	}
};

#endif

#if 0
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//你可以假设数组中无重复元素。
//示例 1:

//输入 : [1, 3, 5, 6], 5
//输出 : 2

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) 
	{
		int i = 0;
		for (i = 0; i < nums.size() && nums[i] < target; i++)
		{
		}
		return i;
	}
};
#endif

#if 0
//给定一个赎金信(ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。如果可以构成，返回 true ；否则返回 false。

//(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)

//注意：

//你可以假设两个字符串均只含有小写字母。

//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) 
	{
		if (ransomNote.length() > magazine.length())
		{
			return false;
		}

		int a[26] = { 0 };
		for (int i = 0; i < magazine.length(); i++)
		{
			//记录验证字符串中每个字符出现的次数
			a[magazine[i] - 'a']++;
		}

		for (int i = 0; i < ransomNote.length(); i++)
		{
			if (--a[ransomNote[i] - 'a'] < 0)
			{
				return false;
			}
		}

		return true;
	}
};

#endif

#if 0
//回文数判断
class Solution {
public:
	bool isPalindrome(int x) 
	{
		if (x < 0)
		{
			return false;
		}
		else
		{
			long long int tmp = x;
			long long int val = 0;
			for (int i = 0; tmp != 0; i = tmp % 10)
			{
				val = (val * 10) + (tmp % 10);
				tmp = tmp / 10;
			}

			if (val == x)
			{
				return true;
			}
		}
		return false;
	}
};
#endif

int main()
{
	int i = 0, a = 0; 
	while (i < 20) 
	{ 
		for (;;) 
		{ 
			if ((i % 10) == 0) 
				break; 
			else i--; 
		}
		i += 11; 
		a += i; 
	}
	system("pause");
	return 0;
}