#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: [7,1,5,3,6,4]
Output: 7   (5-1) + (6-3)

Input: [1,2,3,4,5]
Output: 4   (2-1) + (3-2) + (4-3) + (5-4)

Input: [7,6,4,3,1]
Output: 0
*/

#define mix(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

int maxProfit(vector<int>& prices)
{
	int low = INT_MAX, earn = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		if (prices[i] < low)
			low = prices[i];
		else if (prices[i] > low)
		{
			earn += prices[i] - low;
			low = prices[i];
		}
	}
	return earn;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> nums{ 7,1,5,3,6,4 };
		//vector<int> nums{ 1,2,3,4,5 };
		//vector<int> nums{ 7,6,4,3,1 };
		cout << maxProfit(nums) << "\n";
	}
	return 0;
}