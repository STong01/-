#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
using namespace std;

//两数之和
#if 0
//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
//示例 :
//给定 nums = [2, 7, 11, 15], target = 9
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回[0, 1]
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		map<int, int> A;
		vector<int> b(2, -1);
		for (int i = 0; i<nums.size(); i++)
		{
			if (A.count(target - nums[i]) > 0)
			{
				b[0] = A[target - nums[i]];
				b[1] = i;
				break;
			}
			A[nums[i]] = i;//反过来放入map中，用来获取结果下标
		}
		return b;
	}
};
#endif

//二进制求和
#if 0
//给定两个二进制字符串，返回他们的和（用二进制表示）。
//输入为非空字符串且只包含数字 1 和 0。
//示例 1 :
//输入 : a = "11", b = "1"
//输出 : "100"

class Solution {
public:
	string addBinary(string a, string b) 
	{
		int len_a = a.size();
		int len_b = b.size();
		while (len_a < len_b) 
		{
			a = '0' + a;
			len_a++;
		}
		while (len_a > len_b)
		{
			b = '0' + b;
			len_b++;
		}

		for (int i = len_a - 1; i > 0; i--) 
		{
			a[i] = a[i] - '0' + b[i];
			if (a[i] >= '2') 
			{
				a[i] = (a[i] - '0') % 2 + '0';
				a[i - 1] = a[i - 1] + 1;
			}
		}

		a[0] = a[0] - '0' + b[0];

		if (a[0] >= '2') 
		{
			a[0] = (a[0] - '0') % 2 + '0';
			a = '1' + a;
		}
		return a;
	}
};
#endif

//字符串转换为整数
#if 0
//请你来实现一个 atoi 函数，使其能将字符串转换成整数。
//
//说明：
//假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231, 231 − 1]。如果数值超过这个范围，请返回  INT_MAX(231 − 1) 或 INT_MIN(−231) 。
//
//示例 1 :
//输入 : "4193 with words"
//输出 : 4193
//解释 : 转换截止于数字 '3' ，因为它的下一个字符不为数字。

class Solution {
public:
	int myAtoi(string str) 
	{
		int res = 0;
		int i = 0;
		int flag = 1;

		while (str[i] == ' ') 
		{ 
			i++;
		}

		if (str[i] == '-') 
		{ 
			flag = -1;
		}

		if (str[i] == '+' || str[i] == '-') 
		{ 
			i++;
		}

		while (i < str.size() && isdigit(str[i])) 
		{
			int r = str[i] - '0';

			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)) 
			{
				return flag > 0 ? INT_MAX : INT_MIN;
			}//处理溢出

			res = res * 10 + r;
			i++;
		}
		return flag > 0 ? res : -res;
	}
};
#endif

// 在排序数组中查找元素的第一个和最后一个位置
#if 0
//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//你的算法时间复杂度必须是 O(log n) 级别。
//如果数组中不存在目标值，返回 [-1, -1]。
//示例 1:
//输入 : nums = [5, 7, 7, 8, 8, 10], target = 8
//输出 : [3, 4]

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		vector<int> ret = { -1, -1 };
		if (nums.size() == 0)
			return ret;

		int begin = 0, end = nums.size() - 1;

		if (nums[begin] > target || nums[end] < target)
			return ret;

		while (begin <= end)
		{
			if (nums[begin] == target && nums[end] == target)
			{
				ret[0] = begin;
				ret[1] = end;
				return ret;
			}

			int mid = (begin + end) / 2;

			if (nums[mid] < target)
				begin = mid + 1;

			else if (nums[mid] > target)
				end = mid - 1;

			else
			{
				begin = mid;
				end = mid;
				while (begin >= 0 && nums[begin] == target)
				{
					begin--;
				}
				while (end < nums.size() && nums[end] == target)
				{
					end++;
				}

				ret[0] = begin + 1;
				ret[1] = end - 1;
				return ret;
			}
		}
		return ret;
	}
};
#endif

int a, b; 
void fun() 
{ 
	a = 100; 
	b = 200; 
}

struct HAR 
{ 
	int x, y; 
	struct HAR *p; 
} h[2]; 

int main() 
{ 
	char s[] = "abcdefgh", *p = s; 
	p += 3; 
	printf("%d\n", strlen(strcpy(p, "ABCD")));
	system("pause");
	return 0;
}