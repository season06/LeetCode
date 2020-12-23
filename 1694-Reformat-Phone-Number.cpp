#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: rowIndex = 3
Output: [1,3,3,1]

Input: rowIndex = 0
Output: [1]
*/

// binary search
vector<int> getRow(int rowIndex)
{
	vector<int> ans;
	ans.push_back(1);

	for (int i = 1; i <= rowIndex; i++)
	{
		vector<int> row(i + 1, 1); // vector init (size, value)
		for (int j = 1; j < i; j++)
			row[j] = ans[j - 1] + ans[j];
		ans = row;
	}
	return ans;
}

int main()
{
	int x;
	while (cin >> x)
	{
		vector<int> ans = getRow(x);

		for (auto num : ans)
			cout << num << " ";
		cout << "\n";
	}
	return 0;
}