#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;//输入数组内容个数

	vector<int> a;
	a.resize(n + 1);//定义数组大小
	a[n] = 0;

	int j;
	for (j = 0; j < n; j++)
	{
		cin >> a[j];//输入数组内容
	}

	int i = 0;
	int sum = 0;
	while (i < n)
	{
		if (a[i] > a[i + 1])//数组为非递增数列
		{
			while (i < n && a[i] >= a[i + 1])
			{
				i++;
			}

			sum++;
			i++;
		}
		else if (a[i] == a[i + 1])//内容相等，不影响序列个数
		{
			i++;
		}
		else
		{
			while (i < n && a[i] <= a[i + 1])//数组为非递减数列
			{
				i++;
			}

			sum++;
			i++;
		}
	}

	cout << sum << endl;
	system("pause");
	return 0;
}