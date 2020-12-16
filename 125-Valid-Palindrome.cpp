#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: "A man, a plan, a canal: Panama"
Output: true

Input: "race a car"
Output: false
*/

bool isPalindrome(string s)
{
	string str;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if ((c >= 97 && c <= 122) || (c >= 48 && c <= 57))
			str += c;
		else if (c >= 65 && c <= 90)
			str += (c + 32);
	}
	cout << str << "\n";
	for (int i = 0; i < str.size() / 2; i++)
	{
		if (str[i] != str[str.size() - 1 - i])
			return false;
	}
	return true;
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		cout << isPalindrome(s) << "\n";
	}
	return 0;
}