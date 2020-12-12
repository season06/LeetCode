#include <iostream>
#include <vector>
#include <string>
#include <regex>
using namespace std;

/*
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> ans;

	int i_start = 0, i_end = matrix.size() - 1;
	int j_start = 0, j_end = matrix[0].size() - 1;
	while (1)
	{
		for (int j = j_start; j <= j_end; j++)
			ans.push_back(matrix[i_start][j]);
		i_start++;

		if (i_start > i_end)
			break;

		for (int i = i_start; i <= i_end; i++)
			ans.push_back(matrix[i][j_end]);
		j_end--;

		if (j_start > j_end)
			break;

		for (int j = j_end; j >= j_start; j--)
			ans.push_back(matrix[i_end][j]);
		i_end--;

		if (i_start > i_end)
			break;

		for (int i = i_end; i >= i_start; i--)
			ans.push_back(matrix[i][j_start]);
		j_start++;

		if (j_start > j_end)
			break;
	}
	return ans;
}

int main()
{
	int n;
	while (cin >> n)
	{
		//vector<vector<int>> nums{ {1, 2, 3},{4, 5, 6},{7, 8, 9} };
		//vector<vector<int>> nums{ {1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12} };
		vector<vector<int>> nums{ {1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13,14,15,16} };
		vector<int> ans = spiralOrder(nums);
		for (int a : ans)
			cout << a << " ";
		cout << "\n";
	}
	return 0;
}