// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// may modify the grid in-place if you want
// diagonal cells are not connected — only up/down/left/right

//Edge Case: empty input grid, all land grid, all water grid, general case
// Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid. We visit each cell at most once.
// USE DFS to explore the connected land cells and mark them as visited (by changing '1' to '0') to avoid counting the same island multiple times.
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int r, int c) {
	int rows = grid.size();
	int cols = grid[0].size();
	// Check for out of bounds and if the cell is water ('0')
	if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') {
		return;
	}
	// Mark the current cell as visited by setting it to '0'
	grid[r][c] = '0';
	// Explore the four adjacent directions
	dfs(grid, r - 1, c); // Up
	dfs(grid, r + 1, c); // Down
	dfs(grid, r, c - 1); // Left
	dfs(grid, r, c + 1); // Right
}

int countIslands(vector<vector<char>>& grid) {
	if (grid.empty() || grid[0].empty()) {
		return 0; // Edge case: empty input grid
	}
	int num_islands = 0;
	int rows = grid.size();
	int cols = grid[0].size();
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			if(grid[r][c] == '1') {
				++num_islands;
				dfs(grid,r,c);
			}
		}
	}
	return num_islands;
}