#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Input: nums = [0,1,1]
Output: []

Input: nums = [0,0,0,0]
Output: [[0,0,0]]

Input: nums = [-2,0,1,1,2]
Output: [[-2,0,2],[-2,1,1]]
*/

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (int i = 1; i < nums.size(); i++)
    {
        int target = -nums[i - 1];
        int left = i, right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }
            else if (sum == target)
            {
                vector<int> tmp {nums[i - 1], nums[left], nums[right]};
                result.push_back(tmp);

                // skip duplicate of number 2
                while (left < right && nums[left] == tmp[1])
                    left++;
                // skip duplicate of number 3
                while (left < right && nums[right] == tmp[2])
                    right--;
            }
        }
        // skip duplicate of number 1
        while (i < nums.size() && nums[i - 1] == nums[i])
            i++;
    }

    return result;
}

int main()
{
    // vector<int> nums{-1, 0, 1, 2, -1, -4};
    // vector<int> nums{0, 0, 0, 0};
    // vector<int> nums{-1, 0, 1, 0};
    vector<int> nums{-2, 0, 1, 1, 2};

    vector<vector<int>> result = threeSum(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}