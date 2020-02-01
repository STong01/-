#include <iostream>
#include <string>
using namespace std;

int main()
{

	string s1, s2;
	cin >> s1;

	while (cin >> s2 && getchar() != '\n')
	{
		s1 = s2 + " " + s1;
	}

	cout << s2 << " " << s1 << endl;
	system("pause");
	return 0;
}