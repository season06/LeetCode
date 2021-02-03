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

void setZeroes(vector<vector<int>>& matrix)    /****** time: O(mn), space: O(1) *******/
{
	int m = matrix.size(), n = matrix[0].size(); // col, row
	bool flag_first_col = false, flag_first_row = false;

	// if first col has 0, set flag_first_col = true
	for (int i = 0; i < m; i++)
	{
		if (matrix[i][0] == 0)
		{
			flag_first_col = true;
			break;
		}
	}
	// if first row has 0, set flag_first_row = true
	for (int j = 0; j < n; j++)
	{
		if (matrix[0][j] == 0)
		{
			flag_first_row = true;
			break;
		}
	}

	// traversal all matrix from second col & row, if has 0, flag in first col & row
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}

		}
	}

	// from second col, if first flag is 0, set this whole col to 0
	for (int i = 1; i < m; i++)
	{
		if (matrix[i][0] == 0)
			matrix[i] = vector<int>(n);
	}
	// from second row, if first flag is 0, set this whole row to 0
	for (int j = 1; j < n; j++)
	{
		if (matrix[0][j] == 0)
			for (int i = 1; i < m; i++)
				matrix[i][j] = 0;
	}

	// if flag_first_row=true, set first row to 0
	if (flag_first_row)
		matrix[0] = vector<int>(n);
	// if flag_first_col=true, set first col to 0
	if (flag_first_col)
		for (int i = 0; i < m; i++)
			matrix[i][0] = 0;
}

int main()
{
	//vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
	//vector<vector<int>> matrix = { {0,1,2,0},{3,4,5,2},{1,3,1,5} };
	vector<vector<int>> matrix = { {1,0,3} };
	setZeroes(matrix);
	for (auto row : matrix)
	{
		for (auto n : row)
			cout << n << " ";
		cout << "\n";
	}

	return 0;
}