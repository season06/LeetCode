#include <iostream>
#include <vector>
using namespace std;

/*
Input: cost = [10,15,20]
Output: 15

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
*/

#define MIN(a, b) (a < b ? a : b)

// Button Up DP
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    int *dp = new int[n];
    for (int i = 0; i < n; i++)
    {
        if (i < 2) 
            dp[i] = cost[i];
        else
            dp[i] = cost[i] + MIN(dp[i-1], dp[i-2]);
    }

    return MIN(dp[n-1], dp[n-2]);
}

int main()
{
    vector<int> cost{10, 15, 20};
    cout << minCostClimbingStairs(cost) << endl;

    return 0;
}
