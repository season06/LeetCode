#include <iostream>
#include <vector>
#include <string>
#include <regex>
using namespace std;

/*
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Input: n = 1
Output: [[1]]
*/

vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> ans;
	ans.resize(n);
	for (int i = 0; i < n; i++)
		ans[i].resize(n);

	int count = 1;

	int i_start = 0, i_end = n - 1;
	int j_start = 0, j_end = n - 1;
	while (1)
	{
		for (int j = j_start; j <= j_end; j++)
			ans[i_start][j] = count++;
		i_start++;
		if (count > n * n)
			break;

		for (int i = i_start; i <= i_end; i++)
			ans[i][j_end] = count++;
		j_end--;
		if (count > n * n)
			break;

		for (int j = j_end; j >= j_start; j--)
			ans[i_end][j] = count++;
		i_end--;
		if (count > n * n)
			break;

		for (int i = i_end; i >= i_start; i--)
			ans[i][j_start] = count++;
		j_start++;
		if (count > n * n)
			break;
	}
	return ans;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int>> ans = generateMatrix(n);
		for (auto first : ans)
		{
			for (auto a : first)
				cout << a << " ";
			cout << "\n";
		}
	}
	return 0;
}