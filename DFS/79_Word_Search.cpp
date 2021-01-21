#include <iostream>
#include <vector>
using namespace std;

/*
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
*/

bool dfs(vector<vector<char>>& board, const char* word, int i, int j)
{
	if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || *word != board[i][j])
		return false;
	if (*(word + 1) == '\0') // last word: all match
		return true;

	char visit = board[i][j]; // 不可重複走, 將board的字替換
	board[i][j] = '\0';

	if (dfs(board, word + 1, i - 1, j)) return true; // left
	if (dfs(board, word + 1, i + 1, j)) return true; // right
	if (dfs(board, word + 1, i, j - 1)) return true; // up
	if (dfs(board, word + 1, i, j + 1)) return true; // down

	board[i][j] = visit;
	return false;
}

bool exist(vector<vector<char>>& board, string word)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (dfs(board, word.c_str(), i, j))
				return true;
		}
	}
	return false;
}

int main()
{
	vector<vector<char>> board = { {'A', 'B', 'C', 'E'},
								   {'S', 'F', 'E', 'S'},
								   {'A', 'D', 'E', 'E'} };
	string word;
	while (cin >> word)
	{
		bool ans = exist(board, word);
		cout << ans << "\n";
	}
}