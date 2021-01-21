#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Input: n = 1, k = 1
Output: [[1]]
*/

vector<vector<int>> ans;

void dfs(int n, int k, int cur_num, vector<int> num)
{
	if (num.size() == k)
	{
		ans.push_back(num);
		return;
	}

	for (int i = cur_num; i <= n; i++)
	{
		num.push_back(i);
		dfs(n, k, i + 1, num);
		num.pop_back(); // ´_­ìª¬ºA
	}
	return;
}

vector<vector<int>> combine(int n, int k)
{
	dfs(n, k, 1, vector<int>());
	return ans;
}

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		vector<vector<int>> anss = combine(n, k);
		for (auto i : anss)
		{
			for (auto j : i)
				cout << j << " ";
			cout << "\n";
		}
		ans.clear();
	}
	return 0;
}