#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, res, cur;

	while (cin >> s1)//�����ַ���
	{
		int max = 0;//�����ַ�������

		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] >= '0' && s1[i] <= '9')//�ж��ַ�����
			{
				cur += s1[i];//���������ַ����͵��ַ�
				while (s1[i + 1] >= '0' && s1[i + 1] <= '9')
				{
					i++;
					cur += s1[i];
				}

				if (cur.size() > max)//�ж��ַ��������Ƿ��
				{
					max = cur.size();
					res = cur;
				}
				else if (cur.size() == max)
				{
					res += cur;
				}
			}
			cur.clear();//�����ʱ��ȡ�ַ����ַ���
		}
		cout << res << "," << max << endl;
	}

	system("pause");
	return 0;
}