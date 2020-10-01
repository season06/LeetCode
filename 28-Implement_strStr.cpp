#include <iostream>
#include <string>
using namespace std;

int Horspool(string text, string pattern)
{
	int cur = 0;	// text current position
	int mispos = 0;	// position of pattern is not match to text.
	char mischar;

	while (cur <= text.size - pattern.size())
	{
		bool miss = false;
		// search from right to left (postfix)
		for (int i = pattern.size() - 1; i >= 0 ; i--)
		{
			if (text[i + cur] != pattern[i])
			{
				mischar = text[i + cur];
				mispos = i;
				miss = true;
				break;
			}
		}
		if (!miss) // match success
		{
			return cur;
		}
		for (int i = mispos; i >= 0; i--)
		{
			if (pattern[i] == mischar)	// move number = miss_char position - miss_char last exist position
			{
				cur += (mispos - i);
					break;
			}
			if (i == 0)	// miss character is not in text.
			{
				cur += mispos + 1;
			}
		}
	}
	return -1;
}

int strStr(string haystack, string needle)
{
	return Horspool(haystack, needle);
}

int main()
{
	string haystack, needle;
	while (cin >> haystack >> needle)
	{
		int ans = strStr(haystack, needle);
		cout << ans << "\n";
	}
}

// https://blog.csdn.net/SA14023053/article/details/52067943