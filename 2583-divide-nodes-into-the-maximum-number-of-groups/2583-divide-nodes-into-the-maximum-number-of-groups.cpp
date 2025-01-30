class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1);
        auto isBipartite = [&](int start) -> bool {
            queue<int> q;
            q.push(start);
            color[start] = 1;

            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false; 
                    }
                }
            }

            return true;
        };

        int maxGroups = 0;
        vector<bool> visited(n + 1, false);

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front(); q.pop();
                    component.push_back(node);
                    for (int neighbor : graph[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                if (!isBipartite(component[0])) return -1;

                int longest = 0;
                for (int node : component) {
                    queue<int> bfs;
                    vector<int> depth(n + 1, -1);
                    bfs.push(node);
                    depth[node] = 1;
                    int maxDepth = 1;

                    while (!bfs.empty()) {
                        int u = bfs.front(); bfs.pop();
                        for (int v : graph[u]) {
                            if (depth[v] == -1) {
                                depth[v] = depth[u] + 1;
                                maxDepth = max(maxDepth, depth[v]);
                                bfs.push(v);
                            }
                        }
                    }
                    
                    longest = max(longest, maxDepth);
                }
                maxGroups += longest;
            }
        }

        return maxGroups;
    }
};