#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

/*
Input: coins = [1,2,5], amount = 11
Output: 3

Input: coins = [2], amount = 3
Output: -1

Input: coins = [1], amount = 0
Output: 0
*/

#define MIN(a, b) (a < b ? a : b)

// Button Up DP
int coinChange(vector<int> &coins, int amount)
{
    sort(coins.begin(), coins.end());

    // record the smallest payment method of coin for each amount
    int *dp = new int[amount + 1];
    dp[0] = 0;

    for (int a = 1; a <= amount; a++)
    {
        dp[a] = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int c = coins[i];
            if (a - c < 0)
                break;
            if (dp[a - c] != INT_MAX)
                dp[a] = MIN(dp[a], dp[a - c] + 1);
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main()
{
    vector<int> coins{1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount) << endl;

    return 0;
}
