#include<iostream>
#include <vector>
using namespace std; 

/*
Input: grid = [
				  ["1","1","1","1","0"],
				  ["1","1","0","1","0"],
				  ["1","1","0","0","0"],
				  ["0","0","0","0","0"]
			  ]
Output: 1

Input: grid = [
				  ["1","1","0","0","0"],
				  ["1","1","0","0","0"],
				  ["0","0","1","0","0"],
				  ["0","0","0","1","1"]
			  ]
Output: 3
*/

void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int i, int j)
{
	if (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == '1' && visit[i][j] == false)
	{
		visit[i][j] = true;
		bfs(grid, visit, i - 1, j); // left
		bfs(grid, visit, i + 1, j); // right
		bfs(grid, visit, i, j - 1); // up
		bfs(grid, visit, i, j + 1); // down
	}
}

int numIslands(vector<vector<char>>& grid)
{
	int count = 0;
	vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j] == '1' && visit[i][j] == false)
			{
				count++;
				bfs(grid, visit, i, j);
			}
		}
	}
	return count;
}

int main()
{
	vector<vector<char>> grid = { {'1','1','0','0','0'},
								  {'1','1','0','0','0'},
								  {'0','0','1','0','0'},
								  {'0','0','0','1','1'} };
	cout << numIslands(grid) << "\n";
	system("pause");
}