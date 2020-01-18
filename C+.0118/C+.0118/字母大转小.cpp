#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string toLowerCase(string str) 
	{

		int len = str.length();

		for (int i = 0; i < len; i++)
		{
			char tab = str[i];
			if (tab >= 'A' && tab <= 'Z')
			{
				str[i] = str[i] + 32;
			}
		}

		return str;

	}
};

int main()
{

	system("pause");
	return 0;
}