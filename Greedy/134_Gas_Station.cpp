#include <iostream>
#include <vector>
using namespace std;

/*
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
*/

int canCompleteCircuit_(vector<int>& gas, vector<int>& cost) // Time complexity: O(N^2)
{
    int n = gas.size();
    for (int i = 0; i < n; i++)
    {
        int fuel = 0, j;
        for (j = i; j <= i + n; j++) // circuit, traversal next road
        {
            fuel += gas[j % n];
            if (fuel < cost[j % n])
                break;
            else
                fuel -= cost[j % n];
        }
        if (j - i > n) // j 走完回到原點
            return i;
    }
    return -1;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) // Time complexity: O(N)
{
    int total = 0, sum = 0, start = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        total += gas[i] - cost[i];
        sum += gas[i] - cost[i]; // the point is selected as the starting point.
        if (sum < 0)
        {
            sum = 0;
            start = i + 1;
        }
    }
    if (total >= 0)
        return start;
    return -1;
}

int main()
{
    vector<int> gas{ 1,2,3,4,5 }, cost = { 3,4,5,1,2 };

	cout << canCompleteCircuit(gas, cost) << "\n";

	return 0;
}