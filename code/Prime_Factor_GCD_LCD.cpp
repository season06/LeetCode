#include<iostream>
#include<string>
#include<vector>
using namespace std;

void find_prime_number(int n)
{
	vector<int> prime;
	prime.push_back(2);
	for (int i = 3; i <= n; i += 2)
	{
		int ck = 0;
		for (int j = 0; j < prime.size(); j++)
		{
			if (i % prime[j] == 0)
			{
				ck = 1;
				break;
			}
		}
		if (ck == 0)
			prime.push_back(i);
	}
	for (int i = 0; i < prime.size(); i++)
	{
		if (i == prime.size() - 1)
			cout << prime[i] << "\n";
		else
			cout << prime[i] << " ";
	}
}

void find_factor(int n)
{
	vector<vector<int>> factor; // factor[factor][exponent]
	factor.resize(100);

	int c = 0, time = 0, num = n;
	for (int i = 2; i * i <= n; i++)	// speed up
	{
		while (num % i == 0)
		{
			num /= i;
			time++;
		}
		if (time > 0)
		{
			factor[c].push_back(i);
			factor[c].push_back(time);
			c++;
			time = 0;
		}
	}
	for (int i = 0; i < c; i++)
	{
		cout << factor[i][0];
		if (factor[i][1] > 1)
			cout << "^" << factor[i][1];
		if (i == c - 1)
			cout << "\n";
		else
			cout << " * ";
	}
}

int GCD(int m, int n)
{
	while (n != 0)
	{
		int r = m % n;
		m = n;
		n = r;
	}
	return m;
}
int LCM(int m, int n)
{
	return m * n / GCD(m, n);
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		find_prime_number(n);
		find_factor(n);
		int gcd = GCD(m, n);
		int lcm = LCM(m, n);

		cout << "GCD : " << gcd << "\n";
		cout << "LCM : " << lcm << "\n";
	}
	return 0;
}