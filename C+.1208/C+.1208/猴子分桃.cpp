#include <iostream>
#include <algorithm>
using namespace std;

//猴子分桃
//每次分桃之后都会给老猴子一个桃，所以我们借猴子4个桃，那样每次都可以均分五份
//第一次剩余（x+4）*（4/5）
//第二次剩余（x+4）*（4/5）^2
//…………
//最后剩余（x+4）*（4/5）^n
//则老猴子应该有old=(x + 4) * (4 / 5) ^ n + n - 4
//则最少应该有桃x + 4 = 5 ^ n（最后剩余桃子树必须为整数）
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
