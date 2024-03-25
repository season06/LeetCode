#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Input: candidates = [2], target = 1
Output: []
*/

void backtracking(int start, vector<int> nums, vector<vector<int>> &ans)
{
    if (start == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        backtracking(start + 1, nums, ans);
        if (i == start) continue; // no need to swap self
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> arrs;
    backtracking(0, nums, arrs);
    return arrs;
}

int main()
{
    vector<int> nums{1, 2, 3};
    vector<vector<int>> arrs = permute(nums);

    for (auto arr : arrs) {
        for (auto a : arr) {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
