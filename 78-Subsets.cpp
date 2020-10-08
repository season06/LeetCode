#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
1 2 3
step 0: []
step 1: [] [1]  --> (add 1)
step 2: [] [1] [2] [1 2]  --> (add 2)
stop 3: [] [1] [2] [1 2] [3] [1 3] [2 3] [1 2 3]  --> (add 3)
*/

vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> ans;
	ans.push_back(vector<int>());
	for (int i = 0; i < nums.size(); i++)
	{
		int n = ans.size();
		for (int j = 0; j < n; j++)
		{
			ans.push_back(ans[j]);
			ans[j].push_back(nums[i]);
		}
	}
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
		vector<vector<int>> ans = subsets(nums);
		for (int i = 0; i < ans.size(); i++)
		{
			for (int j = 0; j < ans[i].size(); j++)
			{
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
}