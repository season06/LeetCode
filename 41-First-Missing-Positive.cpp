#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
Input: nums = [3,4,-1,1]
Output: 2

Input: nums = [1,2,0]
Output: 3
*/

// map O(n) & O(1)

#define MAXNUM 300

int firstMissingPositive(vector<int>& nums)
{
	map<int, int> num_dict;
	for (auto num : nums)
		num_dict[num] = 1;

	for (int i = 1; i <= MAXNUM; i++)
	{
		auto iter = num_dict.find(i);
		if (iter == num_dict.end())
			return i;
	}
	return 0;
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

		cout << firstMissingPositive(nums) << "\n";
	}
	return 0;
}