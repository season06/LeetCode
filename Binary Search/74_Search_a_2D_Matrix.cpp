#include <iostream>
#include <vector>
using namespace std;

/*
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int row = matrix.size(), col = matrix[0].size();
	int left = 0, right = row * col - 1; // 將 matrix 攤平一個 array

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (matrix[mid / col][mid % col] == target)
			return true;
		if (matrix[mid / col][mid % col] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return false;
}

int main()
{
	vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
	//int target = 3;
	int target = 13;

	cout << searchMatrix(matrix, target) << "\n";

	return 0;
}