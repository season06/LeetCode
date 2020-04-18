#include<iostream>
#include<string>
#include<stdexcept>
#include<limits>
using namespace std;

string ClearFrontSpace(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			str.erase(i, 1);
			i--;
		}
		else
			return str;
	}
	return str;
}

int myAtoi(string str)
{
	/*		"   -42" -> -42
			"5456 with words" -> 5456
			"words and 987" -> 0
			"-91283472332" -> -2147483648 (out of range)
			"+" -> 0
			"+-2" -> 0
			"   +0 123" -> 0	*/

	// step 1: Eliminate space in front of character.
	if (str[0] == ' ') str = ClearFrontSpace(str);

	// step2: check str[0] is '+' or '-', if not then return 0;
	bool negtive = false;
	if (str[0] == '-') negtive = true;
	else if (str[0] == '+') {}
	else if (!isdigit(str[0])) return 0;
	
	int start = -1, len = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0 && (str[0] == '-' || str[0] == '+'))
			continue;
		if (isdigit(str[i]))
		{	
			if (start == -1)
				start = i;
			len++;
		}
		else		// if the next chracter is not a digit, break.
			break;
	}

	if (start == -1)
		return 0;

	string num_str = str.substr(start, len);
	int num = 0;
	try
	{
		num = stoi(num_str);
		if (negtive)
			num *= -1;
	}
	catch (out_of_range e)
	{
		if (negtive)
			num = numeric_limits<int>::min();
		else
			num = numeric_limits<int>::max();
	}
	
	return num;
}

int main()
{
	string input;
	while (cin >> input)
	{
		input = "  -12  2";
		cout << myAtoi(input) << "\n";
	}
	return 0;
}