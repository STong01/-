#include <iostream>
#include <vector>
using namespace std;

bool is24(vector<double> a,int sum,double tmp)
{
	if (a.size() == 0)
	{
		return tmp == sum;
	}

	for (int i = 0; i < a.size(); i++)
	{
		vector<double> b(a);
		b.erase(b.begin() + i);
		if (is24(b, sum, tmp + a[i]) || is24(b, sum, tmp - a[i])
			|| is24(b, sum, tmp * a[i]) || is24(b, sum, tmp / a[i]))
			return true;

	}

	return false;
}

int main()
{
	vector<double>val;
	for (int i = 0; i < 4; i++)
	{
		cin >> val[i];
	}

	if (is24(val, 24, 0))
	{
		cout << "true" << endl;
	}
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}