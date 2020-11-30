#include<iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target)
{
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		if (nums[i] >= target)
			return i;
	}
	return len;
}

int main()
{
	int n, target;
	while (cin >> n >> target)
	{
		vector<int> nums;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			nums.push_back(tmp);
		}
		cout << searchInsert(nums, target) << "\n";
	}
	return 0;
}