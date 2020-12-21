#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: [7,1,5,3,6,4]
Output: 5  (6-1)

Input: [7,6,4,3,1]
Output: 0
*/

int maxProfit(vector<int>& prices)
{
	if (prices.size() == 0)
		return 0;

	int low = prices[0], earn = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] < low)
			low = prices[i];
		else if (prices[i] > low && prices[i] - low > earn)
			earn = prices[i] - low;
	}
	return earn;
}

int main()
{
	int n;
	while (cin >> n)
	{
		//vector<int> nums{ 7,1,5,3,6,4 };
		vector<int> nums{ 7,6,4,3,1 };
		cout << maxProfit(nums) << "\n";
	}
	return 0;
}