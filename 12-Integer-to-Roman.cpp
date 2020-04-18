#include<iostream>
#include<string>
#include<vector>
using namespace std;

string intToRoman(int num)
{
	vector<int>number = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	vector<string>roman = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	string ans = "";
	for (int i = 0; i < number.size(); i++)
	{
		if (num >= number[i])
		{
			num -= number[i];
			ans += roman[i];
			i--;
		}
	}
	
	return ans;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << intToRoman(n) << "\n";
	}
	return 0;
}