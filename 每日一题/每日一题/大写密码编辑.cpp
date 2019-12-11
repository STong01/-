#include <iostream>
#include <string>
using namespace std;

//密码字母：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
//原文字母：V W X Y Z A B C D E F G H I J K L M N O P Q R S T U

//方案一：
//void test(string s1)
//{
//	char s2[31] = { 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
//		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
//	string s3 = s1;
//	for (int i = 0; i < s1.size(); i++)
//	{
//		for (int j = 5; j < 31; j++)
//		{
//			if (s1[i] == s2[j])
//			{
//				s3[i] = s2[j - 5];
//				break;
//			}
//			else if (s1[i] == ' ')
//			{
//				s3[i] = ' ';
//			}
//		}
//	}
//	cout << s3 << endl;
//}
//
//int main()
//{
//	string s1;
//	while (getline(cin, s1))
//	{
//		test(s1);
//	}
//
//	system("pause");
//	return 0;
//}

//方案二
int main1(){
	int c;
	while ((c = getchar()) != EOF)
	{
		if ('A' <= c) 
		{
			c = 'E' < c ? (c - 5) : (c + 21);
		}
		putchar(c);
	}
	return 0;
}