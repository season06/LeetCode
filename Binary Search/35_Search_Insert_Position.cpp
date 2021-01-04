#include<iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,3,5,6], target = 5
Output: 2

Input: nums = [1,3,5,6], target = 7
Output: 4

Input: nums = [1,3,5,6], target = 0
Output: 0

*/
int searchInsert(vector<int>& nums, int target)
{
	int left = 0, right = nums.size() - 1; // Binary Search, two bound
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			return mid;
		if (target > nums[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

int main()
{
	int target;
	while (cin >> target)
	{
		vector<int> nums{ 1,3,5,6 };
		cout << searchInsert(nums, target) << "\n";
	}
	return 0;
}