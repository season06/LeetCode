#include <iostream>
#include <vector>
using namespace std;

/*
Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Input: s = "11106"
Output: 2
Explanation: "AAJF" (1 1 10 6), "KJF" (11 10 6)

Input: s = "0"
Output: 0

Input: s = "06"
Output: 0
*/

int numDecodings(string s)
{
    if (s[0] == '0')
        return 0;
    if (s.size() == 1)
        return 1;

    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= s.size(); i++)
    {
        int one = s[i - 1] - '0';
        int two = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
        if (one > 0)
            dp[i] += dp[i - 1];
        if (two >= 10 && two < 27)
            dp[i] += dp[i - 2];
    }
    return dp[s.size()];
}

int main()
{
    string s = "";
    while (cin >> s)
        cout << numDecodings(s) << "\n";

    return 0;
}