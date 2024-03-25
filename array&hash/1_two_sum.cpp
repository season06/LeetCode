#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Input: nums = [3,2,4], target = 6
Output: [1,2]

Input: nums = [3,3], target = 6
Output: [0,1]
*/

// Time Complexity: O(n)
vector<int> twoSum(vector<int> &nums, int target)
{
    // use a hash table to store the value we finded: hash(nums_value, index)
    unordered_map<int, int> hash;

    for (int i = 0; i < nums.size(); i++)
    {
        int sub = target - nums[i];
        if (hash.find(sub) == hash.end()) {
            // if sub_value didn't exist in the hash table, then store the current num.
            hash[nums[i]] = i;
        } else {
            // if sub_value existed, output the number's index.
            return vector<int> {hash[sub], i};
        }
    }
    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    for (unsigned int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}