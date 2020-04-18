#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s)
{
	if (s.length() == 0)
		return 0;

	vector<string> substring;
	for (int i = 0; i < s.length(); i++)
	{
		string temp = "";
		int bucket[128] = { 0 };	// every letter has one bucket, if appear, =1
		for (int j = i; j < s.length(); j++)
		{
			if (bucket[s[j]] == 1)		// if letter appears again, push
			{
				substring.push_back(temp);
				temp = "";
				break;
			}
			else
			{
				temp += s[j];
				bucket[s[j]]++;
			}
		}
		if (temp.length() != 0)		// if there is no repeated letter before string read finished, push
			substring.push_back(temp);
	}

	int length = 0;
	string ans = "";
	for (int i = 0; i < substring.size(); i++)
	{
		if (substring[i].length() > length)
		{
			length = substring[i].length();
			ans = substring[i];
		}
	}
	return length;
}

int main()
{
	string s;
	while (cin >> s)
	{
		cout << lengthOfLongestSubstring(s) << "\n";
	}
	return 0;
}