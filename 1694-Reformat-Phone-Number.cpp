#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: number = "1-23-45 6"
Output: "123-456"

Input: number = "123 4-567"
Output: "123-45-67"

Input: number = "123 4-5678"
Output: "123-456-78"
*/

string reformatNumber(string number)
{
	string str = "";
	for (auto n : number)
		if (isdigit(n)) str += n;

	string ans = "";
	int pos = 0;
	while (pos < str.size())
	{
		int remain = str.size() - pos;
		if (remain == 4)
		{
			ans.insert(ans.size(), str, pos, 2);
			pos += 2;
		}
		else if (remain >= 3)
		{
			ans.insert(ans.size(), str, pos, 3);
			pos += 3;
		}
		else
		{
			ans.insert(ans.size(), str, pos, remain);
			break;
		}

		if (pos != str.size())
			ans.append("-");
	}
	return ans;
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		cout << reformatNumber(str) << "\n";
	}
	return 0;
}