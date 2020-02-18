#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> a)
{
	int len_a = a.size();

	for (int i = 0; i< len_a - 1; i++)
	{
		for (int j = 0; j < len_a - 1 - i; j++)
		{
			if (a[j]>a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}

	for (int p = 0; p < len_a; p++)
	{
		cout << a[p] << ' ';
	}
	cout << endl;
}

int main()
{
	vector<int> a = { 1, 3, 5, 2, 7, 8, 0, 2, 3 };
	sort(a);

	system("pause");
	return 0;
}