#include <iostream>
using namespace std;

double myPow(double x, long long int n)
{
	if (n == 0 || x == 1)
		return 1;
	else if (n == 1)
		return x;
	else if (n < 0)
		return myPow(1 / x, -n);

	double ans = 1;
	if (n % 2 == 1)
	{
		ans = x;
		n -= 1;
	}
	ans *= myPow(x * x, n / 2);

	return ans;
}

int main()
{
	double x;
	long long int n;
	while (cin >> x >> n)
	{
		cout << myPow(x, n) << "\n";
	}
	return 0;
}