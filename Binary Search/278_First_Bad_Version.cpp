#include<iostream>
#include <vector>
using namespace std;

/*
Input: n = 5, bad = 4
Output: 4

Input: n = 1, bad = 1
Output: 1

Input: n = 2126753390, bad = 1702766719
Output: 1702766719
*/

int BAD = 0;

bool isBadVersion(int version)
{
	if (version >= BAD)
		return true;
	return false;
}
int firstBadVersion(int n)
{
	long long int left = 0, right = n; // Binary Search
	while (left <= right) // must be first bad version
	{
		long long int mid = (left + right) / 2;
		if (isBadVersion(mid) == false)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

int main()
{
	int n, bad;
	while (cin >> n >> bad)
	{
		BAD = bad;
		cout << firstBadVersion(n) << "\n";
	}
	return 0;
}