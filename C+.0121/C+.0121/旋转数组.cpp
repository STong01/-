#include <iostream>
#include <vector>
using namespace std;

//Ðý×ªÊý×é
//class Solution 
//{
//public:
//	void rotate(vector<int>& nums, int k) 
//	{
//		vector<int> tmp = nums;
//		int p = nums.size();
//		for (int i = 0; i < p; i++)
//		{
//			tmp[((i + k) % p)] = nums[i];
//		}
//		nums = tmp;
//	}
//};

int main()
{
	int x = 10;
	int y = 10;
	x = y = ++y;
	cout << x << y << endl;

	system("pause");

	return 0;
}