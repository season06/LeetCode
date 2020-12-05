#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]

Input: nums = [1]
Output: [1]
*/

/* constant : O(1) -> without array */

void sortColors(vector<int>& nums)
{
	int start = 0, end = nums.size() - 1;
	for (int i = 0; i <= end; i++)
	{
		if (nums[i] == 0)
			swap(nums[start++], nums[i]);
		else if (nums[i] == 2)
			swap(nums[i--], nums[end--]);  // if 2 swap, stay
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> nums;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			nums.push_back(tmp);
		}
		sortColors(nums);

		for (auto num : nums)
			cout << num << " ";
		cout << "\n";
	}
	return 0;
}