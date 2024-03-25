#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Input: digits = ""
Output: []

Input: digits = "2"
Output: ["a","b","c"]
*/

void backtracking(int index, string comb, string &digits, unordered_map<char, string> &phone, vector<string> &ans)
{
    if (comb.size() == digits.size())
    {
        ans.push_back(comb);
        return;
    }

    string letter = phone[digits[index]];
    for (int i = 0; i < letter.size(); i++)
    {
        comb.push_back(letter[i]);
        backtracking(index + 1, comb, digits, phone, ans);
        comb.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.size() == 0)
        return vector<string> {};

    unordered_map<char, string> phone;
    phone['2'] = "abc";
    phone['3'] = "def";
    phone['4'] = "ghi";
    phone['5'] = "jkl";
    phone['6'] = "mno";
    phone['7'] = "pqrs";
    phone['8'] = "tuv";
    phone['9'] = "wxyz";

    vector<string> arrs;
    backtracking(0, "", digits, phone, arrs);
    return arrs;
}

int main()
{
    string digits = "234";
    vector<string> arrs = letterCombinations(digits);

    for (auto str : arrs)
        cout << str << " ";
    cout << endl;

    return 0;
}
