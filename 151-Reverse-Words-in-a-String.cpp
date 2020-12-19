#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/*
Input: s = "the sky is blue"
Output: "blue is sky the"

Input: s = "  hello world  "
Output: "world hello"

Input: s = "a good   example"
Output: "example good a"
*/

string reverseWords(string s)
{
	istringstream input(s);
	vector<string> str;
	string t;
	while (input >> t)
		str.push_back(t);

	string ans = "";
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (i == 0)
			ans += str[i];
		else
			ans += str[i] + " ";
	}
	return ans;
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		cout << reverseWords(str) << "\n";
	}
	return 0;
}