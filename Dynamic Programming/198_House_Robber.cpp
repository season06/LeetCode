#include<iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
			 Total amount you can rob = 1 + 3 = 4.

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
			 Total amount you can rob = 2 + 9 + 1 = 12.
*/

// 搶到 n 間房子的錢 = 第 (n) 間房子的錢 + 搶到 (n-2) 間房子的錢
int rob_(vector<int>& nums)
{
	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return nums[0];

	vector<int> rob(nums.size());
	rob[0] = nums[0];
	rob[1] = max(nums[0], nums[1]);

	for (int i = 2; i < nums.size(); i++)
	{
		rob[i] = max(rob[i - 1], nums[i] + rob[i - 2]);
	}

	return rob.back();
}

// less memory
int rob(vector<int>& nums)
{
	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return nums[0];

	int far = nums[0]; // rob[i - 2]
	int adjacent = max(nums[0], nums[1]); // rob[i - 1]
	int ans = adjacent;

	for (int i = 2; i < nums.size(); i++)
	{
		ans = max(adjacent, nums[i] + far);
		far = adjacent;
		adjacent = ans;
	}

	return ans;
}

int main()
{
	vector<int> nums = { 1,2,3,1 };
	//vector<int> nums = { 7,2,3,9,1 };
	//vector<int> nums = { 1,1 };
	cout << rob(nums) << "\n";

	return 0;
}