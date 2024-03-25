#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Input: s = "a"
Output: [["a"]]
*/

bool isPalindrome(string s)
{
    int left = 0, right = s.size()-1;
    while (left < right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

void backtracking(string s, vector<string> comb, vector<vector<string>> &ans)
{
    if (s.size() == 0)
    {
        ans.push_back(comb);
        return;
    }
    
    for (int i = 1; i <= s.size(); i++)
    {
        string tmp = s.substr(0, i);
        if (!isPalindrome(tmp)) continue;

        comb.push_back(tmp);
        string remain = s.substr(i, s.size());
        backtracking(remain, comb, ans);
        comb.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    backtracking(s, vector<string> {}, ans);
    return ans;
}

int main()
{
    string s = "aabaa";
    vector<vector<string>> result = partition(s);

    for (auto arr : result)
    {
        for (auto a : arr)
        {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
