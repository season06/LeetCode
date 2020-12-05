#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: s = "Hello World"
Output: 5

Input: s = "a "
Output: 1

Input: s = " "
Output: 0
*/


int lengthOfLastWord(string s)
{
	int count = 0;
	int pos = s.size() - 1;  // count from the end of s
	while (s[pos] == ' ')    // skip, if the end of s is space
		pos--;
	while (pos >= 0 && s[pos] != ' ')
	{
		count++;
		pos--;
	}
	return count;
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		cout << lengthOfLastWord(s) << "\n";
	}
	return 0;
}