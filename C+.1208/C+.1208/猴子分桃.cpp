#include <iostream>
#include <algorithm>
using namespace std;

//���ӷ���
//ÿ�η���֮�󶼻���Ϻ���һ���ң��������ǽ����4���ң�����ÿ�ζ����Ծ������
//��һ��ʣ�ࣨx+4��*��4/5��
//�ڶ���ʣ�ࣨx+4��*��4/5��^2
//��������
//���ʣ�ࣨx+4��*��4/5��^n
//���Ϻ���Ӧ����old=(x + 4) * (4 / 5) ^ n + n - 4
//������Ӧ������x + 4 = 5 ^ n�����ʣ������������Ϊ������
void test(int n)
{
	long sum = pow(5, n) - 4;
	long old = pow(4, n) + n - 4;
	cout << sum << " " <<old << endl;

}

int main()
{
	int n;
	while (cin >> n && n > 0)
	{
		test(n);
	}
	system("pause");
	return 0;
}
