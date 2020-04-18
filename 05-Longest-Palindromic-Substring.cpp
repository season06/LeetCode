#include<iostream>
#include<string>
using namespace std;

string fillup(string str)
{
	for (int i = 0; i < str.length(); i += 2)
		str.insert(i, ".");
	str += ".";
	return str;
}

string longestPalindrome(string s)
{
	// Manacher's Algorithm

	// There have two cases in palindromic : odd, even
	// Fill the character to make sure there are only odd-length string.
	s = fillup(s);

	// Start in the center of string, and extend to both sides.
	int start = 1, length = 0;
	for (int i = 1; i < s.length(); i++)
	{
		int L = i - 1, R = i + 1, len = 0;
		while (L >= 0 && R < s.length() && s[L] == s[R])
		{
			L--;
			R++;
			len++;
		}
		if (len > length)	// Record the longest length, and the start position.
		{
			start = i;
			length = len;
		}
	}

	string ans = s.substr(start - length, length * 2 + 1);
	for (int i = 0; i < ans.length(); i++)	// Eliminate characters which added at the beginning.
	{
		if (ans[i] == '.')
			ans.erase(i, 1);
	}
	return ans;
}
int main()
{
	string input;
	while (cin >> input)
	{
		cout << longestPalindrome(input) << "\n";
	}
	return 0;
}