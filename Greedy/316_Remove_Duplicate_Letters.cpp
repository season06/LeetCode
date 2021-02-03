#include <iostream>
#include <vector>
using namespace std;

/*
Input: s = "bcabc"
Output: "abc"

Input: s = "cbacdcbc"
Output: "acdb"
*/

/*
remove duplicate letters, every letter appears only once
the smallest in lexicographical-order
remain letter sequence
*/
string removeDuplicateLetters(string s) // Time complexity: O(n)
{
	string ans = "0";
	int count[26] = { 0 };
	bool visited[26] = { false };

	// �p��C�Ӧr���X�{������
	for (auto c : s)
		count[c - 'a']++;

	for (auto c : s)
	{
		count[c - 'a']--;
		if (visited[c - 'a']) // �w�b ans ��, �B��m�w�w�Ƨ���
			continue;
		// �ˬd ans �̫᪺�r��, �Y c ���p, �B�̫᪺��r�b���U���٦��X�{, �h�N ans �̫�@�Ӧr���R��
		while (c < ans.back() && count[ans.back() - 'a'] > 0)
		{
			visited[ans.back() - 'a'] = false;
			ans.pop_back();
		}
		ans += c;
		visited[c - 'a'] = true;
	}
	return ans.substr(1);
}

int main()
{
	//string s = "bcabc";
	string s = "cbacdcbc";

	cout << removeDuplicateLetters(s) << "\n";

	return 0;
}