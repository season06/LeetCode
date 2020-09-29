#include <iostream>
using namespace std;

int climbStairs(int n)
{
	int ans = 0, one = 1, two = 1;
	if (n == 0 || n == 1)
	{
		return 1;
	}
	for (int i = 2; i <= n; i++)
	{
		ans = one + two;
		one = two;
		two = ans;
	}
	return ans;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int ans = climbStairs(n);
		cout << ans << "\n";
	}
}