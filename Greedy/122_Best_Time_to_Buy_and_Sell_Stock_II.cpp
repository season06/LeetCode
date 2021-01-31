#include <iostream>
#include <vector>
using namespace std;

/*
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
			 Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
			 Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
			 engaging multiple transactions at the same time. You must sell before buying again.

Input: [7,6,4,3,1]
Output: 0
*/

int maxProfit(vector<int>& prices)
{
	int maxProfit = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i - 1] < prices[i])
			maxProfit += prices[i] - prices[i - 1];
	}
	return maxProfit;
}

int main()
{
	vector<int> nums{ 7,1,5,3,6,4 };

	cout << maxProfit(nums) << "\n";

	return 0;
}