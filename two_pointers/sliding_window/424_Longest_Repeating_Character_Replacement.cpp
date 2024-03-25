#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Input: s = "ABAB", k = 2
Output: 4    // AAAA

Input: s = "AABABBA", k = 1
Output: 4    // AABBBBA
*/

#define MAX(a, b) (a > b ? a : b)

int characterReplacement(string s, int k)
{
    int left = 0, maxCount = 0, ans = 0;
    unordered_map<char, int> count;
    for (int right = 0; right < s.size(); right++)
    {
        count[s[right]]++;                         // record the count of each letter in current length
        maxCount = MAX(maxCount, count[s[right]]); // check if the new letter is the maximum count
        while (right - left + 1 - maxCount > k)    // if current length exceeds k times replacement, then move the right's sliding window
        {
            count[s[left]]--;
            left++;
        }
        ans = MAX(ans, right - left + 1);
    }
    return ans;
}

int main()
{
    string s = "AABABBA";
    int k = 1;
    cout << characterReplacement(s, k) << endl;

    return 0;
}
