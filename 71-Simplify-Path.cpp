#include <iostream>
#include <vector>
#include <string>
#include <regex>
using namespace std;

/*
Input: path = "/home/"
Output: "/home"

Input: path = "/../"
Output: "/"

Input: path = "/home//foo/"
Output: "/home/foo"

Input: path = "/a/./b/../../c/"
Output: "/c"
*/

string simplifyPath(string path)
{
	regex reg("(/[a-zA-Z0-9_\.]+)");  // regular expression
	smatch match;

	vector<string> match_word;
	while (regex_search(path, match, reg))  // match all substring
	{
		if (match[0].compare("/..") == 0)
		{
			if (match_word.size() != 0)
				match_word.pop_back();
		}
		else if (match[0].compare("/.") != 0)
			match_word.push_back(match[0]);

		path = match.suffix().str();  // continue the remaining words
	}

	if (match_word.size() == 0)
		return "/";
	else
	{
		string ans = "";
		for (auto word : match_word)
			ans.append(word);
		return ans;
	}
}

int main()
{
	string str;
	while (cin >> str)
	{
		cout << simplifyPath(str) << "\n";
	}
	return 0;
}