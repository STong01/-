#include <iostream>
#include <string>
using namespace std;

//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数

int main()
{
	int M, N;
	string S ;//保存转换后的进制数
	string tab = "0123456789ABCDEF";//进制数转换参照数

	cin >> M >> N;//输入十进制数和需要转换的进制数N

	bool flag = true;//判断M是否为负数的标记

	if (M < 0)
	{
		M = 0 - M;
		flag = false;
	}

	while (M)
	{
		S = tab[M % N] + S;//取余
		M = M / N;//求商
	}

	if (!flag)
	{
		S = '-' + S;
	}

	cout << S << endl;

	system("pause");
	return 0;
}