#include <iostream>
#include <vector>
using namespace std;

/*
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

Input: s1 = "", s2 = "", s3 = ""
Output: true
*/

#define MIN(a, b) (a < b ? a : b)

bool isInterleave(string s1, string s2, string s3)
{
    bool dp[s1.size() + 1][s2.size() + 1];

    for (int i = 0; i <= s1.size(); i++)
    {
        for (int j = 0; j <= s2.size(); j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            else if (j == 0)
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
            else
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }

    for (int i = 0; i <= s1.size(); i++)
    {
        for (int j = 0; j <= s2.size(); j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[s1.size()][s2.size()];
}

int main()
{
    string s1 = "abc", s2 = "cb", s3 = "abccb";
    cout << isInterleave(s1, s2, s3) << endl;
    return 0;
}
