#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//子集
#if 0
//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//说明：解集不能包含重复的子集。
//示例 :
//输入 : nums = [1, 2, 3]
//利用位运算进行计算，其中nums = [1, 2, 3]
//其中000 ->[], 001 ->[3], 010 ->[2], 011 ->[2, 3], 100 ->[1], 101->[1, 3]
//110->[1, 2], 111->[1, 2, 3];

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		int len = nums.size();
		int sum = 1 << len;
		vector<vector<int>> res;

		for (int i = 0; i < sum; i++)
		{
			vector<int> tmp;
			for (int j = 0; j < len; j++)
			{
				if (i & (1 << j))
				{
					tmp.push_back(nums[j]);
				}
			}
			res.push_back(tmp);
		}
		return res;
	}
};
#endif

//二叉树的右视图
#if 0
//给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
//示例 :
//输入 : [1, 2, 3, null, 5, null, 4]
//输出 : [1, 3, 4]

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) 
	{
		vector<int> tmp;
		if (!root) 
			return tmp;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) 
		{
			int len = q.size();
			for (int i = 0; i < len; i++) 
			{
				TreeNode* node = q.front(); 
				q.pop();
				if (node->left) 
					q.push(node->left);
				if (node->right) 
					q.push(node->right);
				if (i == len - 1) 
					tmp.push_back(node->val);
			}
		}
		return tmp;
	}
};
#endif

//通配符匹配
#if 0
//给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
//
//'?' 可以匹配任何单个字符。
//'*' 可以匹配任意字符串（包括空字符串）。
//两个字符串完全匹配才算匹配成功。
//说明 :
//s 可能为空，且只包含从 a - z 的小写字母。
//p 可能为空，且只包含从 a - z 的小写字母，以及字符  ? 和 *。
//示例 1 :
//输入 :
//	s = "adceb"
//	p = "*a*b"
//输出 : true
//解释 : 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".

class Solution {
public:
	bool isMatch(string s, string p) 
	{
		int i = 0, j = 0;
		int isum = -1, jsum = -1;
		int m = s.size(), n = p.size();
		while (i < m)
		{
			if (j < n && (s[i] == p[j] || p[j] == '?')) 
			{
				++i, ++j;
			}
			else if (j < n && p[j] == '*') 
			{
				isum = i;
				jsum = j++;
			}
			else if (isum >= 0) 
			{
				i = ++isum;
				j = jsum + 1;
			}
			else 
				return false;
		}
		while (j < n && p[j] == '*') 
			++j;
		return j == n;
	}
};
#endif


int main()
{


	system("pause");
	return 0;
}