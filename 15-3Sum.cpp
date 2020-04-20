#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> ans;
	if (nums.size() == 0)  return ans;
	
	sort(nums.begin(), nums.end()); // 排序
	if (nums[0] > 0) return ans;

	int low = 0, high = 0, n = nums.size();
	for (int i = 0; i < n - 2; i++)
	{
		if (i != 0 && nums[i - 1] == nums[i]) // 重複的跳過
			continue;

		low = i + 1;	// i, low, , , high
		high = n - 1;
		
		while (low < high)
		{
			int sum = nums[i] + nums[low] + nums[high];
			if (sum < 0)
				low++;
			else if (sum > 0)
				high--;
			else if (sum == 0)
			{
				ans.push_back({nums[i], nums[low], nums[high]});

				while (low + 1 < n && nums[low] == nums[low + 1])
					low++;
				while (high - 1 >= 0 && nums[high] == nums[high - 1])
					high--;
				low++;
				high--;
			}
		}
	}
	return ans;
}

int main()
{
	string input;
	while (getline(cin,input))
	{
		stringstream ss(input);
		vector<int> nums;
		string temp;
		while (ss >> temp)
			nums.push_back(stoi(temp));

		vector<vector<int>> ans = threeSum(nums);
		for (int i = 0; i < ans.size(); i++)
		{
			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;
}