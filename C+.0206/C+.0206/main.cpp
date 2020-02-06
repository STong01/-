#include <iostream>
#include <vector>
using namespace std;

//按奇偶排序数组
#if 0
//给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。
//你可以返回满足此条件的任何数组作为答案。
//
//示例：
//输入：[3, 1, 2, 4]
//输出：[2, 4, 3, 1]
//输出[4, 2, 3, 1]，[2, 4, 1, 3] 和[4, 2, 1, 3] 也会被接受。

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A)
	{
		vector<int> B(A.size(), 0);
		int i = 0;
		int j = A.size() - 1;
		int p = 0;
		while (i <= j && p < A.size())
		{
			if (A[p] % 2 == 0)
			{
				B[i] = A[p];
				i++;
				p++;
			}
			else
			{
				B[j] = A[p];
				j--;
				p++;
			}
		}
		return B;
	}
};
#endif

//寻找数组的中心索引
#if 0
//给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
//我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
//如果数组不存在中心索引，那么我们应该返回 - 1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
//示例 1:
//输入 :
//	nums = [1, 7, 3, 6, 5, 6]
//输出 : 3
//解释 :
//	索引3(nums[3] = 6) 的左侧数之和(1 + 7 + 3 = 11)，与右侧数之和(5 + 6 = 11)相等。
//	同时, 3 也是第一个符合要求的中心索引。
class Solution {
public:
	int pivotIndex(vector<int>& nums) 
	{
		for (int i = 0; i < nums.size(); i++)
		{
			int sum1 = 0;
			int sum2 = 0;
			for (int j = 0; j < i; j++)
			{
				sum1 += nums[j];
			}
			for (int p = i + 1; p < nums.size(); p++)
			{
				sum2 += nums[p];
			}
			if (sum1 == sum2)
			{
				return i;
			}
		}
		return -1;
	}
};
#endif

//加一
#if 0
//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//你可以假设除了整数 0 之外，这个整数不会以零开头。
//示例 1 :
//输入 : [1, 2, 3]
//输出 : [1, 2, 4]
// 解释 : 输入数组表示数字 123。

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) 
	{
		for (int j = digits.size() - 1; j >= 0; j--)
		{
			if (digits[j] < 9)
			{
				digits[j] += 1;
				return digits;
			}
			else if (j == 0 && digits[j] == 9)
			{
				vector<int> digits1(digits.size() + 1, 0);
				digits1[0] = 1;
				return digits1;
			}
			else
			{
				digits[j] = 0;
			}
		}
		return digits;
	}
};
#endif

//第三大的数（O(n)复杂度）
#if 0
//给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
//示例 1:
//输入 : [3, 2, 1]
//输出 : 1
// 解释 : 第三大的数是 1.

class Solution {
public:
	int thirdMax(vector<int>& nums) 
	{
		long long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > max1)
			{
				max3 = max2;
				max2 = max1;
				max1 = nums[i];
			}
			else if (nums[i] < max1 && nums[i] > max2)
			{
				max3 = max2;
				max2 = nums[i];
			}
			else if (nums[i] < max2 && nums[i] > max3)
				max3 = nums[i];
		}
		if (max3 != LONG_MIN)
			return max3;
		else
			return max1;
	}
};
#endif

int f(int n) 
{ 
	if (n) 
		return f(n - 1) + n; 
	else 
		return n; 
}

int fun(int x, int y) 
{ 
	if (x == y) 
		return (x); 
	else
		return((x + y) / 2); 
}

int main()
{
	int a = 4, b = 5, c = 6; 
	printf("%d\n", fun(2 * a, fun(b, c)));

	system("pause");
	return 0;
}