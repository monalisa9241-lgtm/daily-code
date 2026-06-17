//Minimum coin change required to make a certain amount of money given a set of coin denominations,
// but use BFS approach instead of DP.
//visited array to avoid cycles and ensure we don't revisit the same amount multiple times.
//Bound the search to amounts less than or equal to the target amount to optimize performance 
// and prevent unnecessary exploration of larger amounts that cannot contribute to the solution.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;

    queue<int> q;
    vector<bool> visited(amount + 1, false);

    q.push(0);
    visited[0] = true;

    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        steps++;

        while (size--) {
            int curr = q.front(); q.pop();

            for (int coin : coins) {
                int next = curr + coin;

                if (next == amount) return steps;

                if (next < amount && !visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }

    return -1;
}