#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: nums = [2,2,1]
Output: 1

Input: nums = [4,1,2,1,2]
Output: 4

Input: nums = [1]
Output: 1
*/

int singleNumber(vector<int>& nums)
{
	for (int i = 1; i < nums.size(); i++) // xor : a¡òb¡òa = (a¡òa)¡òb = 0¡òb = b
		nums[0] ^= nums[i];

	return nums[0];
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> nums;
		nums.resize(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];

		cout << singleNumber(nums) << "\n";
	}
	return 0;
}