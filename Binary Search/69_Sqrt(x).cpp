#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: x = 4
Output: 2

Input: x = 8
Output: 2
*/

// binary search
int mySqrt(int x)
{
	int ans = 0;
	int left = 1, right = x / 2 + 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (mid * mid == x)
			return mid;
		else if (mid * mid < x)
		{
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return ans;
}

int main()
{
	int x;
	while (cin >> x)
	{
		cout << mySqrt(x) << "\n";
	}
	return 0;
}