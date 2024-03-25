#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Input: s = "anagram", t = "nagaram"
Output: true

Input: s = "rat", t = "car"
Output: false
*/

bool isAnagramSort(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

bool isAnagram(string s, string t)
{
    if (s.size() != t.size()) {
        return false;
    }

    unordered_map<char, int> count;
    for (unsigned int i = 0; i < s.size(); i++) {
        count[s[i]]++;
        count[t[i]]--;
    }
    for (auto c : count) {
        if (c.second != 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "anagram", t = "nagaram";

    cout << isAnagram(s, t) << endl;

    return 0;
}