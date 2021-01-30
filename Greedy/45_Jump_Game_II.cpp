#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Input: nums = [2,3,0,1,4]
Output: 2
*/

int jump(vector<int>& nums) // Time complexity: O(N) Space complexity: O(1)
{
	int i = 0, level = 0, maxStep = 0;
	while (maxStep < nums.size() - 1)
	{
		level++;
		int preStep = maxStep;
		for (; i <= preStep; i++) // traverse of preStep level and find the max step of this level
			maxStep = max(maxStep, i + nums[i]);
	}

	return level;
}

int main()
{
	// vector<int> nums = { 2,3,1,1,4 };
	vector<int> nums = { 2,3,0,1,4 };

	cout << jump(nums) << "\n";

	return 0;
}