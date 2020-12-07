#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: digits = [1,2,3]
Output: [1,2,4]

Input: digits = [9]
Output: [1,0]
*/

vector<int> plusOne(vector<int>& digits)
{
	digits[digits.size() - 1] ++;

	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (digits[i] >= 10)
		{
			digits[i] = 0;
			if (i == 0)
				digits.insert(digits.begin(), 1);
			else
				digits[i - 1]++;
		}
		else
			break;
	}
	return digits;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> nums;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			nums.push_back(tmp);
		}
		vector<int> ans = plusOne(nums);

		for (auto a : ans)
			cout << a << " ";
		cout << "\n";
	}
	return 0;
}