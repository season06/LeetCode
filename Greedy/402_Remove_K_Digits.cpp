#include <iostream>
#include <vector>
using namespace std;

/*
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Input: num = "123", k = 3
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

Input: num = "10", k = 1
Output: "0"

Input: num = "1230", k = 3
Output: "0"
*/

string removeKdigits(string num, int k) // Time Complexity : O(n)
{
	if (k >= num.size())
		return "0";

	vector<char> stack;

	// greedy & stack(只放小的數字)
	for (char character : num)
	{
		while (k > 0 && !stack.empty() && stack.back() > character)
		{
			stack.pop_back();
			k--;
		}
		stack.push_back(character);
	}

	// 把剩下的 k 用完, 從最後開始刪除
	stack.resize(stack.size() - k);

	// 移除高位數的 0
	while (stack.front() == '0' && stack.size() > 1)
		stack.erase(stack.begin());

	string ans(stack.begin(), stack.end());
	return ans;
}

string removeKdigits_(string num, int k)
{
	if (k >= num.size())
		return "0";

	int i = 1;
	while (i < num.size() && k > 0)
	{
		while (k > 0 && i > 0 && num[i - 1] > num[i])
		{
			num.erase(num.begin() + i - 1);
			k--;
			i--;
		}
		i++;
	}

	num = num.substr(0, num.size() - k);

	while (num.front() == '0' && num.size() > 1)
		num.erase(num.begin());

	return num;
}

int main()
{
	string num = "1432219";
	int k = 3;

	cout << removeKdigits(num, k) << " ";

	return 0;
}