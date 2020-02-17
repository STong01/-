#include <iostream>
#include <vector>
using namespace std;

//ð������
void bubblesort(vector<int> a)
{
	//ʱ�临�Ӷȣ�O(n2)  �ռ临�Ӷȣ�O(1)  �ȶ����� 
	int len_a = a.size();
	//��ǰ���Ԫ�غͺ����Ԫ�رȽϣ����������һֱ����ȥ����С�����ݸ�����
	for (int i = 0; i < len_a - 1; i++)
	{
		for (int j = 0; j < len_a - 1 - i; j++)//����ȥ��������ʱ��ıȽ��������ٱȽ�
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	//��ӡ����
	for (int i = 0; i < len_a; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

//ѡ������
void selectsort(vector<int> a)
{
	//ʱ�临�Ӷȣ�O(n2)  �ռ临�Ӷȣ�O(1)  ���ȶ����� 
	int len_a = a.size();
	//�����ҵ������е���С��Ԫ�أ�����СԪ�غ�����ĵ�һ��Ԫ�ؽ������Դ˽���Сֵ������ĵڶ���Ԫ�ؽ������Դ���ȥ�������
	for (int i = 0; i < len_a; i++)
	{
		int min = i;
		for (int j = i + 1; j < len_a; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}

		int tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
	}
	//��ӡ����
	for (int i = 0; i < len_a; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

//��������
void insertsort(vector<int> a)
{
	//ʱ�临�Ӷȣ�O(n2)  �ռ临�Ӷȣ�O(1)  �ȶ�����
	int len_a = a.size();
	//�Ǻ����������ǰ���Ѿ��ĺ�������ݴӺ���ǰ����һһ�Ƚϣ�ֱ���������Լ�С�����ݣ����Լ��嵽�����ݵĺ���
	for (int i = 1; i < len_a; i++)
	{
		int tmp = a[i];
		int k = i - 1;
		while (k >= 0 && a[k] > tmp)
		{
			k--;
		}
		for (int j = i; j > k + 1; j--)
		{
			a[j] = a[j - 1];
		}
		a[k + 1] = tmp;
	}
	//��ӡ����
	for (int i = 0; i < len_a; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

//������
//�����ѣ��Դ����Ϊ��
void head(vector<int>a, int start, int n)
{
	int parent = start;
	int child = 2 * parent + 1;

	while (child <= n)
	{
		if (child + 1 <= n && a[child] < a[child + 1])
		{
			child++;
		}

		if (a[child] < a[parent])
		{
			break;
		}

		int tmp = a[parent];
		a[parent] = a[child];
		a[child] = tmp;
		parent = child;
		child = 2 * parent + 1;
	}
}

void headsort(vector<int>a)
{
	int len_a = a.size();

	for (int i = len_a / 2 - 1; i >= 0; i--)
	{
		head(a, i, len_a - 1);
	}
	//������
	for (int i = len_a - 1; i > 0; i--)
	{
		int tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		head(a, 0, i - 1);
	}
	//��ӡ����
	for (int i = 0; i < len_a; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main()
{
	vector<int> b = { 12, 4, 132, 55, 46, 232, 789, 1, 0, 98, 523, 666 };
	int len_b = b.size();
	headsort(b);

	system("pause");
	return 0;
}
