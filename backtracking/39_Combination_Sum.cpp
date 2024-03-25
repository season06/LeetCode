#include <iostream>
#include <vector>
using namespace std;

/*
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Input: candidates = [2], target = 1
Output: []
*/

void backtracking(int start, vector<int> comb, vector<int> nums, int remind, vector<vector<int>> &ans)
{
    if (remind < 0) return;
    if (remind == 0) {
        ans.push_back(comb);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        comb.push_back(nums[i]);
        backtracking(i, comb, nums, remind-nums[i], ans);
        comb.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &nums, int target)
{
    vector<vector<int>> arrs;
    backtracking(0, vector<int>{}, nums, target, arrs);
    return arrs;
}

int main()
{
    vector<int> nums{2, 3, 5};
    int target = 8;
    vector<vector<int>> arrs = combinationSum(nums, target);

    for (auto arr : arrs) {
        for (auto a : arr) {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
