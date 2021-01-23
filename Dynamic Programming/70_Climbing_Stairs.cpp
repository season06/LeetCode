#include <iostream>
using namespace std;

/*
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

// 走到n-1階的方法 = 走到(n-2)階的方法 + 走到(n-3)階的方法
int climbStairs(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}

	int ans = 0, one = 1, two = 1;
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