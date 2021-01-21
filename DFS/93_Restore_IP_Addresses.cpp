#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Input: s = "0000"
Output: ["0.0.0.0"]
*/

vector<string> ans;

void dfs(string s, string ip, int pos, int count)
{
	if (s.size() - pos != 0 && count == 4) // �Y�w��4�ռƦr�A�� s �٥����� -> false
		return;
	if (count == 4) // ip �ѥ|�ռƲզ�
	{
		ip = ip.substr(0, ip.size() - 1);
		ans.push_back(ip);
		return;
	}

	for (int i = 1; i <= 3 && pos + i <= s.size(); i++) // �̦h�T�ӼƦr
	{
		string tmp = s.substr(pos, i);
		if (tmp.size() > 1 && tmp[0] == '0' || stoi(tmp) > 255) // �Ĥ@�줣�i��0, ���i�W�L255
			break;
		dfs(s, ip + tmp + '.', pos + i, count + 1);
	}
	return;
}

vector<string> restoreIpAddresses(string s)
{
	dfs(s, "", 0, 0);
	return ans;
}

int main()
{
	string s;
	while (cin >> s)
	{
		vector<string> anss = restoreIpAddresses(s);
		for (auto i : anss)
			cout << i << "\n";
		ans.clear();
	}
	return 0;
}