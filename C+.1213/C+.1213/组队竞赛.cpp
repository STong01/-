#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ţţ�ٰ���һ�α�̱���, �μӱ�������3*n��ѡ��, ÿ��ѡ�ֶ���һ��ˮƽֵa_i.����Ҫ����Щѡ�ֽ������, һ�����n������, ��ÿ������3��.ţţ���ֶ����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��
//�������Ϊ :
//team1 : {1, 2, 5}, team2 : {5, 5, 8}, ��ʱ��ˮƽֵ�ܺ�Ϊ7.
//���������Ϊ :
//team1 : {2, 5, 8}, team2 : {1, 5, 5}, ��ʱ��ˮƽֵ�ܺ�Ϊ10.

int main()
{
	int n;
	while (cin >> n)//��������
	{
		long long sum = 0;
		vector<int> a;
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];//����ÿ�������
		}

		//����
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
		
		//ͳ�Ʋ��������
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