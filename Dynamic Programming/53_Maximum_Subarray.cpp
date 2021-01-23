#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

int maxSubArray(vector<int>& nums)
{
	int max = nums[0];
	int sum = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		if (sum + nums[i] > nums[i])
			sum += nums[i];
		else
			sum = nums[i];
		if (sum > max)
			max = sum;
	}
	return max;
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
		cout << maxSubArray(nums) << "\n";
	}
	return 0;
}