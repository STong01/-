#include<iostream>
#include<vector>
using namespace std;

bool is24(const vector<double>& a, int sum, double tmp) 
{
	if (a.empty())//µİ¹éÖÕÖ¹Ìõ¼ş
	{
		return sum == tmp;
	}

	for (int i = 0; i < a.size(); i++)
	{
		vector<double>b(a);
		b.erase(b.begin() + i);
		if (is24(b, sum, tmp + a[i]) ||
			is24(b, sum, tmp - a[i]) ||
			is24(b, sum, tmp * a[i]) ||
			is24(b, sum, tmp / a[i]))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	vector<double>a(4, 0);

	while (cin >> a[0] >> a[1] >> a[2] >> a[3])
	{
		if (is24(a, 24, 0))
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	system("pause");
	return 0;
}