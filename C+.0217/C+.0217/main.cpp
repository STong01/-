#include <iostream>
#include <vector>
using namespace std;

//冒泡排序
void bubblesort(vector<int> a)
{
	//时间复杂度：O(n2)  空间复杂度：O(1)  稳定排序 
	int len_a = a.size();
	//拿前面的元素和后面的元素比较，将大的数据一直沉下去，将小的数据浮上来
	for (int i = 0; i < len_a - 1; i++)
	{
		for (int j = 0; j < len_a - 1 - i; j++)//沉下去的数据在时候的比较中无须再比较
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	//打印检验
	for (int i = 0; i < len_a; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

//选择排序
void selectsort(vector<int> a)
{
	//时间复杂度：O(n2)  空间复杂度：O(1)  非稳定排序 
	int len_a = a.size();
	//首先找到数组中的最小的元素，将最小元素和数组的第一个元素交换，以此将次小值和数组的第二个元素交换，以此下去完成排序
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
	//打印检验
	for (int i = 0; i < len_a; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

//插入排序
void insertsort(vector<int> a)
{
	//时间复杂度：O(n2)  空间复杂度：O(1)  稳定排序
	int len_a = a.size();
	//那后面的数据与前面已经拍好序的数据从后往前进行一一比较，直到遇到比自己小的数据，将自己插到此数据的后面
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
	//打印检验
	for (int i = 0; i < len_a; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

//堆排序
//构建堆，以大根堆为主
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
	//堆排序
	for (int i = len_a - 1; i > 0; i--)
	{
		int tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		head(a, 0, i - 1);
	}
	//打印检验
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
