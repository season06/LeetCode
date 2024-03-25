#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
*/

bool dfs(int i, int j, int count, vector<vector<char>> &board, string word)
{
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        return false;
    if (board[i][j] != word[count])
        return false;
    if (count == word.size() - 1)
        return true;

    char tmpChar = board[i][j];
    board[i][j] = '.';
    count++;
    bool result = dfs(i - 1, j, count, board, word) || dfs(i + 1, j, count, board, word) || dfs(i, j - 1, count, board, word) || dfs(i, j + 1, count, board, word);
    board[i][j] = tmpChar;

    return result;
}

bool exist(vector<vector<char>> &board, string word)
{

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (dfs(i, j, 0, board, word))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";

    cout << exist(board, word) << endl;

    return 0;
}
