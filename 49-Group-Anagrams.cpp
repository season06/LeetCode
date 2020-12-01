#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
/*
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

dict = {
	"aet": ["eat", "ate", "tea"],
	"ant": ["nat", "tan"],
	"abt": ["bat"]
}
*/

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	vector<vector<string>> ans;
	if (strs.size() == 0)
		return ans;

	map<string, vector<string>> dict;
	for (int i = 0; i < strs.size(); i++)
	{
		string word = strs[i];
		sort(word.begin(), word.end());
		dict[word].push_back(strs[i]);
	}

	map<string, vector<string>>::iterator iter;
	for (iter = dict.begin(); iter != dict.end(); iter++)
	{
		vector<string> words = iter->second;
		ans.push_back(words);
	}
	return ans;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> strs;
		for (int i = 0; i < n; i++)
		{
			string tmp;
			cin >> tmp;
			strs.push_back(tmp);
		}
		vector<vector<string>> output = groupAnagrams(strs);
		for (int i = 0; i < output.size(); i++)
		{
			for (int j = 0; j < output[i].size(); j++)
			{
				cout << output[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}