#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: 5
Output:
[
	 [1],
	[1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

// binary search
vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> ans;

	for (int i = 0; i < numRows; i++)
	{
		vector<int> row(i + 1, 1); // vector init (size, value)
		for (int j = 1; j < i; j++)
			row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
		ans.push_back(row);
	}
	return ans;
}

int main()
{
	int x;
	while (cin >> x)
	{
		vector<vector<int>> ans = generate(x);
		for (auto first : ans)
		{
			for (auto num : first)
			{
				cout << num << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}