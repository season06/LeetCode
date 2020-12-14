#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

/*
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

void setZeroes(vector<vector<int>>& matrix)
{
	set<int> row, col;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == 0)
			{
				row.insert(i);
				col.insert(j);
			}
		}
	}
	for (set<int>::iterator it = col.begin(); it != col.end(); it++)
	{
		for (int i = 0; i < matrix.size(); i++)
			matrix[i][*it] = 0;
	}
	for (set<int>::iterator it = row.begin(); it != row.end(); it++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
			matrix[*it][j] = 0;
	}
}

int main()
{
	int target;
	while (cin >> target)
	{
		//vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
		//vector<vector<int>> matrix = { {0,1,2,0},{3,4,5,2},{1,3,1,5} };
		vector<vector<int>> matrix = { {1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0} };
		setZeroes(matrix);
		for (auto row : matrix)
		{
			for (auto n : row)
				cout << n << " ";
			cout << "\n";
		}

	}
	return 0;
}