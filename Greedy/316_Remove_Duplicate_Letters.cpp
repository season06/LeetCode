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

	// 計算每個字母出現的次數
	for (auto c : s)
		count[c - 'a']++;

	for (auto c : s)
	{
		count[c - 'a']--;
		if (visited[c - 'a']) // 已在 ans 中, 且位置已安排妥當
			continue;
		// 檢查 ans 最後的字母, 若 c 較小, 且最後的單字在接下來還有出現, 則將 ans 最後一個字母刪除
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