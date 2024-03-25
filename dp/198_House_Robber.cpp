#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,2,3,1]
Output: 4

Input: nums = [2,7,9,3,1]
Output: 12

Input: nums = [2,1,1,2]
Output: 4
*/

#define MAX(a, b) (a > b ? a : b)

// Button Up DP
int rob(vector<int> &nums)
{
    nums.insert(nums.begin(), 0);
    int n = nums.size();
    int *dp = new int[n];
    for (int i = 0; i < n; i++)
    {
        if (i < 2)
            dp[i] = nums[i];
        else
            dp[i] = MAX(dp[i-1], dp[i-2] + nums[i]);
    }

    return dp[n-1];
}

int robWithTwoVariables(vector<int> &nums)
{
    int prev2 = 0, prev1 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int tmp = prev1;
        prev1 = MAX(prev2 + nums[i], prev1);
        prev2 = tmp;
    }

    return prev1;
}

int main()
{
    vector<int> nums{2, 1, 1, 2};
    cout << rob(nums) << endl;

    return 0;
}
