#include <iostream>
#include <vector>
using namespace std;

/*
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Input: height = [4,2,0,3,2,5]
Output: 9
*/

int trap(vector<int> &height)
{
    // The target is to find maxLeft & maxRight, and subtract them from current two pointer.
    int left = 0, right = height.size() - 1, ans = 0;
    int maxLeft = 0, maxRight = 0;
    while (left < right) {
        if (height[left] < height[right])
        {
            if (height[left] > maxLeft)
                maxLeft = height[left];
            else
                ans += maxLeft - height[left];
            left++;
        } else {
            if (height[right] > maxRight)
                maxRight = height[right];
            else
                ans += maxRight - height[right];
            right--;
        }
    }
    return ans;
}

int main()
{
    vector<int> height{4, 2, 0, 3, 2, 5};
    cout << trap(height) << endl;

    return 0;
}
