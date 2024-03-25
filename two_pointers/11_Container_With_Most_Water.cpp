#include <iostream>
#include <vector>
using namespace std;

/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

Input: height = [1,1]
Output: 1
*/

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

int maxArea(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1, fill = 0;
    while (left < right)
    {
        int current = MIN(height[left], height[right]);
        fill = MAX(fill, current*(right-left));
        if (height[left] < height[right]) {
            left++;
        } else{
            right--;
        }
    }
    return fill;
}

int main()
{
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;

    return 0;
}