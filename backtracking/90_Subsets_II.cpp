#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Input: nums = [0]
Output: [[],[0]
*/

void backtracking(int start, vector<int> comb, vector<int> nums, vector<vector<int>> &ans)
{
    ans.push_back(comb);

    for (int i = start; i < nums.size(); i++)
    {
        if (i > start && nums[i] == nums[i-1]) continue; // skip duplicate
        comb.push_back(nums[i]);
        backtracking(i + 1, comb, nums, ans);
        comb.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> arrs;
    backtracking(0, vector<int>{}, nums, arrs);
    return arrs;
}

int main()
{
    vector<int> nums{2, 1, 2};
    vector<vector<int>> arrs = subsets(nums);

    for (auto arr : arrs)
    {
        for (auto a : arr)
        {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
