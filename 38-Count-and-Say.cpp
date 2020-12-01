#include <iostream>
#include <vector>
#include <string>
using namespace std;

string countAndSay(int n)
{
	string num_str = "1";
	for (int i = 1; i < n; i++)
	{
		vector<char> num;
		vector<int> count;
		for (int j = 0; j < num_str.size(); j++)
		{
			if (num.size() == 0 || num.back() != num_str[j])
			{
				num.push_back(num_str[j]);
				count.push_back(1);
			}
			else
			{
				count[count.size() - 1]++;
			}
		}
		num_str = "";
		for (int j = 0; j < num.size(); j++)
		{
			num_str += to_string(count[j]);
			num_str += num[j];
		}
	}
	return num_str;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << countAndSay(n) << "\n";
	}
	return 0;
}