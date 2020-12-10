#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Input:
[
	 [2],
	[3,4],
   [6,5,7],
  [4,1,8,3]
]
Output: 11 (2 + 3 + 5 + 1 = 11)

Input:
[
	 [-1],
	[2,3],
  [1,-1,-3]
]
Output: -1
*/

#define min(a, b) (a < b ? a : b)

int minimumTotal(vector<vector<int>>& triangle)
{
	for (int i = 1; i < triangle.size(); i++) // in place
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				triangle[i][j] += triangle[i - 1][0];
			else if (j == i)
				triangle[i][j] += triangle[i - 1][i - 1];
			else
				triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
		}
	}
	int ans = *min_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
	return ans;
}

int main()
{
	int x;
	while (cin >> x)
	{
		vector<vector<int>> nums;
		for (int i = 0; i < x; i++)
		{
			vector<int> row;
			row.resize(i + 1);
			for (int j = 0; j <= i; j++)
				cin >> row[j];
			nums.push_back(row);
		}

		cout << minimumTotal(nums) << "\n";
	}
	return 0;
}