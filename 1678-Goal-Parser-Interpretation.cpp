#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: command = "G()(al)"
Output: "Goal"

Input: command = "(al)G(al)()()G"
Output: "alGalooG"
*/

string interpret(string command)
{
	string ans = "";
	for (int i = 0; i < command.size(); i++)
	{
		if (command[i] == 'G')
			ans += 'G';
		else if (command[i] == '(')
		{
			if (command[i + 1] == ')')
			{
				ans += 'o';
				i += 1;
			}
			else
			{
				ans += "al";
				i += 3;
			}
		}
	}
	return ans;
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		cout << interpret(str) << "\n";
	}
	return 0;
}