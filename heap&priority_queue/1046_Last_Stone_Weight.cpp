#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
Input: stones = [2,7,4,1,8,1]
Output: 1
*/

/*
From small to large:
priority_queue<T, vector<T>, greater<T>> pq;
*/

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int, vector<int>> pq(stones.begin(), stones.end()); // [8, 7, 4, 2, 1, 1]

    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        pq.push(a - b);
    }
    return pq.top();
}

int main()
{
    vector<int> stones{2, 7, 4, 1, 8, 1};
    cout << lastStoneWeight(stones) << endl;

    return 0;
}