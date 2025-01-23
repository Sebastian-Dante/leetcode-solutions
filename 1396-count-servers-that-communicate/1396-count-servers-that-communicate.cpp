class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Vectors to store the count of servers in each row amd column
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        // First pass: count servers in each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        // Second Pass: count servers that can ommunicate
        int count = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j) {
                // A server can communicate if its row or column has more than one server
                if(grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1)){
                    count++;
                }
            }
        }

        return count;


        
    }
};