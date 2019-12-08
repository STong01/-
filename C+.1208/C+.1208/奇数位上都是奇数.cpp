#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	*  奇数位上都是奇数或者偶数位上都是偶数
	*  输入：数组arr，长度大于2
	*  len：arr的长度
	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	*/
	//每次选择最后一个数进行判断，奇数放在奇数位，偶数放在偶数位，
	void oddInOddEvenInEven(vector<int>& arr, int len) 
	{
		int i = 0;
		int j = 1;
		while (i < len && j < len)
		{
			if (arr[len - 1] % 2 == 0)
			{
				swap(arr[len - 1], arr[i]);
				i += 2;
			}

			else
			{
				swap(arr[len - 1], arr[j]);
				j += 2;
			}
		}
	}
};

int main()
{

	system("pause");
	return 0;

}