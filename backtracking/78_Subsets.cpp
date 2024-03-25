#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Input: nums = [0]
Output: [[],[0]]
*/

void backtracking(int start, vector<int> comb, vector<int> nums, vector<vector<int>> &ans)
{
    ans.push_back(comb);

    for (int i = start; i < nums.size(); i++) {
        comb.push_back(nums[i]);
        backtracking(i + 1, comb, nums, ans);
        comb.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> arrs;
    backtracking(0, vector<int>{}, nums, arrs);
    return arrs;
}

int main()
{
    vector<int> nums{1, 2, 3};
    vector<vector<int>> arrs = subsets(nums);

    for (auto arr : arrs) {
        for (auto a : arr) {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
