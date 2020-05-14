#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

void sum(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &temp, int now)
{
	if (target == 0)
	{
		ans.push_back(temp);
		return;
	}

	for (int i = now; i < candidates.size() && target>=candidates[i]; i++)
	{
		temp.push_back(candidates[i]);
		sum(candidates, target - candidates[i], ans, temp, i);
		temp.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> ans;
	vector<int> temp;
	
	sort(candidates.begin(), candidates.end());
	sum(candidates, target, ans, temp, 0); // recursion

	return ans;
}

int main()
{
	string input;
	while (getline(cin, input))
	{
		stringstream ss(input);
		vector<int> nums;
		string temp;
		while (ss >> temp)
			nums.push_back(stoi(temp));

		int target = nums[nums.size() - 1];
		nums.pop_back();
		vector<vector<int>> ans = combinationSum(nums, target);
		for (int i = 0; i < ans.size(); i++)
		{
			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;
}