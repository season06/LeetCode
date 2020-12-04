#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
Input: nums = [2,3,1,1,4]
Output: true

Input: nums = [3,2,1,0,4]
Output: false

input nums = [1]
Output: true

input nums = [2,0]
Output: true

input nums = [2,5,0,0]
Output: true
*/

#define MAX(a,b) (a>b?a:b)

bool canJump(vector<int>& nums)
{
	int max = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > max)	// if length > max step
			return false;

		max = MAX(nums[i] + i, max);

		if (max >= nums.size() - 1) // if exceed the length of the array
			return true;
	}
	return true;
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

		cout << canJump(nums) << "\n";
	}
	return 0;
}