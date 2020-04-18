#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

map<string, string> phone = {
	{"2", "abc"}, {"3", "def"}, {"4", "ghi"}, {"5", "jkl"}, {"6", "mno"}, {"7", "pqrs"}, {"8", "tuv"}, {"9", "wxyz"}
};

void backtrack(vector<string> &ans, string digit, string str)
{
	if (digit.length() == 0)
	{
		ans.push_back(str);
		return;
	}
	else
	{
		string c(1, digit[0]);
		map<string, string>::iterator iter = phone.find(c);
		string letter = iter->second;
		digit.erase(0, 1);
		for (int i = 0; i < letter.length(); i++)
			backtrack(ans, digit, str + letter[i]);
	}
}

vector<string> letterCombinations(string digits) 
{
	vector<string> ans;

	if (digits.length() == 0)
		return ans;
	
	backtrack(ans, digits, "");
	return ans;
}

int main()
{
	string num;
	while (cin >> num)
	{
		vector<string> ans = letterCombinations(num);
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << "\n";
	}
	return 0;
}