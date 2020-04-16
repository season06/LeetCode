#include<iostream>
#include<string>
#include<vector>
using namespace std;

string convert(string s, int numRows)
{
	if (numRows == 1)
		return s;
	vector<string> str;
	str.resize(numRows);
	int n = 0, i = 0;
	bool back = false;
	while (i < s.length())
	{
		str[n] += s[i++];
		if (n == numRows - 1)
		{
			back = true;
			n--;
		}
		else if (n == 0)
		{
			back = false;
			n++;
		}
		else if (back == false)
			n++;
		else if (back == true)
			n--;
	}

	string ans = "";
	for (int i = 0; i < numRows; i++)
		ans += str[i];
	return ans;
}

int main()
{
	string input;
	int n;
	while (cin >> input >> n)
	{
		cout << convert(input, n) << "\n";
	}
	return 0;
}