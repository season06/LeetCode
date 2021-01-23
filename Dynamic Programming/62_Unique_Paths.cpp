#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: m = 3, n = 7
Output: 28

Input: m = 3, n = 2
Output: 3
*/

int uniquePaths(int m, int n)
{
	if (m == 1 || n == 1)
		return 1;

	// init
	vector<vector<int>> board;
	board.resize(m, vector<int>(n));
	for (int i = 0; i < m; i++)
		board[i][0] = 1;
	for (int i = 0; i < n; i++)
		board[0][i] = 1;

	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			board[i][j] = board[i - 1][j] + board[i][j - 1]; // 走到左邊的方法數 + 走到上面的方法數

	return board[m - 1][n - 1];
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		cout << uniquePaths(m, n) << "\n";
	}
	return 0;
}