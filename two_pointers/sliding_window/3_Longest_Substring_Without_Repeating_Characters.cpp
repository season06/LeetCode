#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
Input: s = "abcabcbb"
Output: 3

Input: s = "bbbbb"
Output: 1

Input: s = "pwwkew"
Output: 3
*/

/*
## unordered_set
insert(): add element
erase() : delete specified element
count() : whether the element exists // 1: exist, 0: not exist
clear() : clear set
empty() : check whether set is empty
*/

#define MAX(a, b) (a > b ? a : b)

int lengthOfLongestSubstring(string s)
{
    int left = 0, ans = 0;
    unordered_set<char> st;
    for (int right = 0; right < s.size(); right++)
    {
        if (st.count(s[right]) == 0) {  // if letter not exist
            st.insert(s[right]);
            ans = MAX(ans, right - left + 1);
        } else {                        // if letter exist
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
        }
    }
    return ans;
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}
