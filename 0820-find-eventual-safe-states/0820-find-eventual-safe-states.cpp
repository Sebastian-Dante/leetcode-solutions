class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n, 0);
        vector<vector<int>> reverseGraph(n);

        // Create reverse graph and compute outdegree of each node
        for (int i = 0; i < n; ++i) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
                outdegree[i]++;
            }
        }

        // Start with all terminal nodes ( nodes with outdegree 0)
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safeNodes;

        // Perform reverse BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int neighbor : reverseGraph[node]) {
                outdegree[neighbor]--;
                if (outdegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Sort the safe nodes in ascending order
        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
   
    }

};