#include<iostream>
#include <vector>
using namespace std;

/*
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/

// circle: two cases: To rob, or not to rob
int rob(vector<int>& nums)
{
	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return nums[0];

	// case 1: rob house 0 -> 
	int far = nums[0];
	int adjacent = nums[0]; // house 1 can't be robbed
	int ans1 = adjacent;
	for (int i = 2; i < nums.size() - 1; i++) // last house can't be robbed
	{
		ans1 = max(adjacent, nums[i] + far);
		far = adjacent;
		adjacent = ans1;
	}

	// case 2: don't rob house n ->
	far = 0;
	adjacent = nums[1];
	int ans2 = adjacent;
	for (int i = 2; i < nums.size(); i++)
	{
		ans2 = max(adjacent, nums[i] + far);
		far = adjacent;
		adjacent = ans2;
	}

	return max(ans1, ans2);
}

int main()
{
	//vector<int> nums = { 1,2,3,1 };
	//vector<int> nums = { 2,3,2 };
	vector<int> nums = { 0 };
	cout << rob(nums) << "\n";

	return 0;
}