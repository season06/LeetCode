#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]

Input: intervals = [[1,5]], newInterval = [2,7]
Output: [[1,7]]

Input: intervals = [[1,5]], newInterval = [6,8]
Output: [[1,5], [6,8]]
*/

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
	vector<vector<int>> ans;

	for (auto interval : intervals)
	{
		if(!(interval[0] > newInterval[1] || interval[1] < newInterval[0])) // 
		{
			newInterval[0] = min(newInterval[0], interval[0]);
			newInterval[1] = max(newInterval[1], interval[1]);
		}
		else
			ans.push_back(interval);
	}
	auto iter = upper_bound(ans.begin(), ans.end(), newInterval); // return first num which '>=' the number we search
	ans.insert(iter, newInterval);

	return ans;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int>> intervals;
		vector<int> new_interval(2);
		for (int i = 0; i < n; i++)
		{
			vector<int> num(2);
			cin >> num[0] >> num[1];
			intervals.push_back(num);
		}
		cout << "Input new interval: ";
		cin >> new_interval[0] >> new_interval[1];

		vector<vector<int>> output = insert(intervals, new_interval);

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