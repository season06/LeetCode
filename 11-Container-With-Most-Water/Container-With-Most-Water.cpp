#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)

int maxArea(vector<int>& height)
{
	int n = height.size();
	int left = 0, right = n - 1, max_area = 0;
	while (left < right)	// Two Pointer Approach
	{
		int min_container = MIN(height[left], height[right]);
		max_area = MAX(max_area, min_container*(right - left));
		if (height[left] < height[right])
			left++;
		else
			right--;
	}
	return max_area;
}

int main()
{
	string input;
	while (getline(cin, input))
	{
		vector<int> num;
		for (int i = 0; input[i]!='\0'; i++)
		{
			if (isdigit(input[i]))
				num.push_back(input[i] - 48);
		}
		cout << maxArea(num) << "\n";
	}
	return 0;
}