#include<iostream>
#include<string>
#include<vector>
using namespace std;
void backtrack(vector<string> &ans, string par, int left, int right, int n)
{
	if (par.length() == n * 2)
	{
		ans.push_back(par);
		return;
	}
	if (left < n)
		backtrack(ans, par+"(", left+1, right, n);
	if(right < left)
		backtrack(ans, par+")", left, right+1, n);
}

vector<string> generateParenthesis(int n)
{
	vector<string> ans;
	backtrack(ans, "", 0, 0, n);

	return ans;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> ans = generateParenthesis(n);
		for(int i=0;i<ans.size();i++)
			cout << ans[i] << "\n";
	}
	return 0;
}