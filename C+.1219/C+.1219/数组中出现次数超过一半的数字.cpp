#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> n1) 
	{
		int q = n1.size();//记录数组的长度

		//冒泡排序
		for (int i = 0; i < q - 1; i++)
		{
			for (int j = 0; j < q - i - 1; j++)
			{
				if (n1[j] > n1[j + 1])
				{
					int tmp = n1[j];
					n1[j] = n1[j + 1];
					n1[j + 1] = tmp;
				}
			}
		}

		int p = n1[q / 2];//记录数组中的中间位置数字（如果存在超过数组长度一半的数字，那么这个数字一定是数组排序中间的数字）

		int sum = 0;

		for (int i = 0; i < q; i++)
		{
			if (n1[i] == p)
			{
				sum++;//记录中间数字出现的次数
			}
		}

		if (sum > (q / 2))//如果数字次数超过一半，则输出，否则输出0
		{
			return p;
		}
		else
		{
			return 0;
		}
	}
};

int main()
{
	vector<int> n1 = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };

	for (int i = 0; i < n1.size() - 1; i++)
	{
		for (int j = 0; j < n1.size() - i - 1; j++)
		{
			if (n1[j] > n1[j + 1])
			{
				int tmp = n1[j];
				n1[j] = n1[j + 1];
				n1[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < n1.size(); i++)
	{
		cout << n1[i] << endl;
	}

	system("pause");
	return 0;
}