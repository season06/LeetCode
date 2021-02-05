#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.
*/

int findMin(vector<int>& nums)
{
	int left = 0, right = nums.size() - 1;
	int ans = nums[0];

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] >= nums[0]) // 順序正常, 往右找
			left = mid + 1;
		else                     // rotate, 往左找是否有更小的數字
		{
			ans = nums[mid];
			right = mid - 1;
		}
	}

	return ans;
}

int main()
{
	vector<int> nums = { 3,4,5,1,2 };
	//vector<int> nums = { 11,13,15,17 };
	//vector<int> nums = { 2,1 };

	cout << findMin(nums) << "\n";

	return 0;
}