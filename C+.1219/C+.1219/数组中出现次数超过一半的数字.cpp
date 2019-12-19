#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> n1) 
	{
		int q = n1.size();

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

		int p = n1[q / 2];

		int sum = 0;

		for (int i = 0; i < q; i++)
		{
			if (n1[i] == p)
			{
				sum++;
			}
		}

		if (sum > (q / 2))
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