#include <iostream>
#include <string>
using namespace std;

//����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������

int main()
{
	int M, N;
	string S ;//����ת����Ľ�����
	string tab = "0123456789ABCDEF";//������ת��������

	cin >> M >> N;//����ʮ����������Ҫת���Ľ�����N

	bool flag = true;//�ж�M�Ƿ�Ϊ�����ı��

	if (M < 0)
	{
		M = 0 - M;
		flag = false;
	}

	while (M)
	{
		S = tab[M % N] + S;//ȡ��
		M = M / N;//����
	}

	if (!flag)
	{
		S = '-' + S;
	}

	cout << S << endl;

	system("pause");
	return 0;
}