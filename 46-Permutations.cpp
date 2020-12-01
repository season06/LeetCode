#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input: nums = [1,1,2]
Output: [[1,1,2], [1,2,1], [2,1,1]]

Input: nums = [1,2,3]
Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
*/

vector<vector<int>> ans;
void permuteRecursion(vector<int>& new_nums, vector<int>& nums)
{
	if (nums.size() == 0)
	{
		ans.push_back(new_nums);
		return;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		new_nums.push_back(nums[i]);

		vector<int> num = nums;
		num.erase(num.begin() + i); // set new nums array, length = len(nums) - 1

		permuteRecursion(new_nums, num);
		new_nums.pop_back(); // remove last recursion element
	}
}

vector<vector<int>> permute(vector<int>& nums)
{
	vector<int> new_nums;
	permuteRecursion(new_nums, nums);
	return ans;
}

int main()
{
	int n;
	vector<int> nums;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			nums.push_back(temp);
		}

		vector<vector<int>> output = permute(nums);
		for (int i = 0; i < output.size(); i++)
		{
			for (int j = 0; j < output[i].size(); j++)
			{
				cout << output[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}