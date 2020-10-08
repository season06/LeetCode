#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isFound(vector<vector<char>>& board, const char* word, int x, int y)
{
	if (x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] == '\0' || *word != board[x][y])
		return false;
	if (*(word+1) == '\0')
		return true;

	char tmp = board[x][y];
	board[x][y] = '\0';

	if (isFound(board, word + 1, x - 1, y) || isFound(board, word + 1, x, y - 1) || isFound(board, word + 1, x + 1, y) || isFound(board, word + 1, x, y + 1))
		return true;
	else
		board[x][y] = tmp;
		return false;
}
bool exist(vector<vector<char>>& board, string word)
{
	for (int i = 0; i < board.size(); i++)
	{		
		for (int j = 0; j < board[i].size(); j++)
		{
			if (isFound(board, word.c_str(), i, j))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	vector<vector<char>> board = { // CESEEEF
			{'A', 'B', 'C', 'E'},
			{'S', 'F', 'E', 'S'},
			{'A', 'D', 'E', 'E'}
	};
	string word;
	while (cin >> word)
	{
		bool ans = exist(board, word);
		cout << ans << "\n";
	}
}