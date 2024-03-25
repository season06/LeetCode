#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [10,5,2,6], k = 100
Output: 8
// contiguous subarrays: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]

Input: nums = [1,2,3], k = 0
Output: 0
*/

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    // constraint: 1 <= nums[i] <= 1000
    if (k <= 1) return 0;

    int left = 0;
    int product = 1, ans = 0;

    // sliding window
    for (int right = 0; right < nums.size(); right++) {
        product *= nums[right];

        while (product >= k) {
            product /= nums[left];
            left++;
        }

        // the count of number in the window
        ans += right - left + 1;
    }
    return ans;
}

int main()
{
    vector<int> nums{1, 2, 3};
    int k = 1;
    cout << numSubarrayProductLessThanK(nums, k) << endl;

    return 0;
}