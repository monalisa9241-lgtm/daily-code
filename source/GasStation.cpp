//find and return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.
#include <vector>
#include <iostream>	
using namespace std;

class Solution {
public:
	int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) 
	{
		int n = gas.size();
		int totalGas = 0;
		int totalCost = 0;

		for (int i = 0; i < n; i++)
		{
			totalCost += cost[i];
			totalGas += gas[i];
		}
		if (totalCost > totalCost)
		{
			return -1;
		}
		
		int currentGas = 0;
		int startStation = 0;

		for (int i = 0; i < n; ++i)
		{
			currentGas += gas[i] - cost[i];
			if (currentGas < 0)
			{
				startStation = i + 1;
				currentGas = 0;
			}
		}
		return startStation;
	}
};