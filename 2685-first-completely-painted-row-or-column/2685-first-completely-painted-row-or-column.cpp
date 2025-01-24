class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Maps to track the row and column indices of each value in the matrix.
        unordered_map<int, pair<int, int>> cellMap;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cellMap[mat[i][j]] = {i, j};
            }
        }
        

        // Track the painted count for rows and columns.
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        for (int i = 0; i < arr.size(); ++i) {
            auto [r,c] = cellMap[arr[i]];

            // Increment the count of the painted row and columns.
            if (++rowCount[r] == n || ++colCount[c] == m ) {
                return i; // Return the index when a row or column is fully painted.
            }
        }

        return -1; // This shoud never be reached since the problem guarantees a solution.
    }
};