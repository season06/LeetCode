#include <iostream>
#include <vector>
using namespace std;

/*
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 ¡÷ 3 ¡÷ 1 ¡÷ 1 ¡÷ 1 minimizes the sum.

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*/

int minPathSum(vector<vector<int>>& grid)
{
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (i == 0)
				grid[i][j] += grid[i][j - 1]; // boundary of top
			else if (j == 0)
				grid[i][j] += grid[i - 1][j]; // boundary of left
			else
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]); // The cost of middle grid += min(top, left)
		}
	}
	return grid.back().back();
}

int main()
{
	//vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1} };
	vector<vector<int>> grid = { {1,2,3},{4,5,6} };

	cout << minPathSum(grid) << "\n";

	return 0;
}