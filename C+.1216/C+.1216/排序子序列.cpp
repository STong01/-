#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;//�����������ݸ���

	vector<int> a;
	a.resize(n + 1);//���������С
	a[n] = 0;

	int j;
	for (j = 0; j < n; j++)
	{
		cin >> a[j];//������������
	}

	int i = 0;
	int sum = 0;
	while (i < n)
	{
		if (a[i] > a[i + 1])//����Ϊ�ǵ�������
		{
			while (i < n && a[i] >= a[i + 1])
			{
				i++;
			}

			sum++;
			i++;
		}
		else if (a[i] == a[i + 1])//������ȣ���Ӱ�����и���
		{
			i++;
		}
		else
		{
			while (i < n && a[i] <= a[i + 1])//����Ϊ�ǵݼ�����
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