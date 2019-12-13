#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//牛牛举办了一次编程比赛, 参加比赛的有3*n个选手, 每个选手都有一个水平值a_i.现在要将这些选手进行组队, 一共组成n个队伍, 即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
//如果方案为 :
//team1 : {1, 2, 5}, team2 : {5, 5, 8}, 这时候水平值总和为7.
//而如果方案为 :
//team1 : {2, 5, 8}, team2 : {1, 5, 5}, 这时候水平值总和为10.

int main()
{
	int n;
	while (cin >> n)//输入组数
	{
		long long sum = 0;
		vector<int> a;
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];//输入每组的数据
		}

		//排序
	/*	for (int i = 0; i < (3 * n) - 1; i++)
		{
			for (int j = 0; j < (3 * n) - i - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					int tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
				}
			}
		}*/
		std::sort(a.begin(), a.end());
		
		//统计并输出数据
		sum = 0;
		for (int i = n; i < 3 * n; i += 2)
		{
			sum += a[i];
		}

		cout << sum << endl;
	}

	system("pause");
	return 0;
}