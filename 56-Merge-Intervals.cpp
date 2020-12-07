#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]

Input: intervals = [[1,4],[0,4]]
Output: [[0,4]]

Input: intervals = [[2,3],[4,5],[6,7],[8,9],[1,10]]
Output: [[1,10]]
*/

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	sort(intervals.begin(), intervals.end()); // important

	vector<vector<int>> ans;
	ans.push_back(intervals[0]);

	int count = 0;
	for (int i = 1; i < intervals.size(); i++)
	{
		if (ans[count][1] >= intervals[i][0]) // if overlap
			ans[count][1] = max(ans[count][1], intervals[i][1]);
		else
		{
			ans.push_back(intervals[i]);
			count++;
		}
	}
	return ans;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int>> intervals;
		for (int i = 0; i < n; i++)
		{
			vector<int> num(2);
			cin >> num[0] >> num[1];
			intervals.push_back(num);
		}
		vector<vector<int>> output = merge(intervals);

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