class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int findMaxFish = 0;

        // Helper function for DFS
        auto dfs = [&](int r, int c, auto& dfs) -> int {
            // Base case: If out of bounds or land cell, return 0
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0 ) {
                return 0;
            }

            // Collect fish at current cell
            int fish = grid[r][c];
            grid[r][c] = 0; // Mark the cell as visited 

            // Explore all adjacent cells
            fish += dfs(r + 1, c, dfs);
            fish += dfs(r - 1, c, dfs);
            fish += dfs(r, c + 1, dfs);
            fish += dfs(r, c - 1, dfs);

            return fish;
        };

        // Iterate over all cells in the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) { // Start DFS from water cells
                    findMaxFish = max(findMaxFish, dfs(i, j, dfs));
                }
            }
        }

        return findMaxFish;

        
    }
};