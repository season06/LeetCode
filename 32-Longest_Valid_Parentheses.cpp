#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int longestValidParentheses(string s) {
	if (s.size() == 0 || s.size() == 1)
		return 0;

	int len = 0;

	// check from left to right
	int left_pos = 0;
	int n = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			n++;
		else
		{
			n--;
			if (n == 0)
			{
				len = max(len, i - left_pos + 1);
			}
		}
		if (n < 0)
		{
			n = 0;
			left_pos = i + 1;
		}
	}

	// check from right to left
	int right_pos = s.size() - 1;
	n = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == ')')
			n++;
		else
		{
			n--;
			if (n == 0)
			{
				len = max(len, right_pos - i + 1);
			}
		}
		if (n < 0)
		{
			n = 0;
			right_pos = i - 1;
		}
	}
	return len;
}

int main()
{
	string str;
	while (cin >> str)
	{
		int ans = longestValidParentheses(str);
		cout << ans << "\n";
	}
}