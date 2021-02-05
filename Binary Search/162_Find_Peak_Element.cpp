#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
*/

// can only find 'local' peak element
int findPeakElement(vector<int>& nums)
{
	int left = 0, right = nums.size() - 1;

	while (left < right) // 最後 left, mid, right 三個指針會指在同一個 peak
	{
		int mid = (left + right) / 2;
		if (nums[mid] < nums[mid + 1]) // 右邊的元素較大, 繼續向右找
			left = mid + 1;
		else
			right = mid; // left 與 right 不重疊
	}

	return left;
}

int main()
{
	//vector<int> nums = { 1,3,5,6,4 };
	//vector<int> nums = { 1,2,3,1 };
	//vector<int> nums = { 1,2,1,3,5,6,4 };
	vector<int> nums = { 1,5,2,1,3,4,5 };

	cout << findPeakElement(nums) << "\n";

	return 0;
}