#include <iostream>
#include <vector>
using namespace std;

/*
Input: prices = [7,1,5,3,6,4]
Output: 5

Input: prices = [7,6,4,3,1]
Output: 0
*/

#define MAX(a, b) (a > b ? a : b)

int maxProfit(vector<int> &prices)
{
    int left = 0, ans = 0;
    for (int right = 1; right < prices.size(); right++)
    {
        if (prices[left] < prices[right]) {
            ans = MAX(ans, prices[right]-prices[left]);
        } else {
            left = right;
        }
    }
    return ans;
}

int main()
{
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;

    return 0;
}