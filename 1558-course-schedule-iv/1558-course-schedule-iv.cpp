class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Create a 2D vector to represent the adjacency matrix for prerequisites
        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));

        // Mark direct prerequisites in the adjacency matrix
        for (const auto& pre : prerequisites) {
            isPrerequisite[pre[0]][pre[1]] = true;
        }

        // Use Floyd-Warshall algorithm to compute the transitive closure
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    if (isPrerequisite[i][k] && isPrerequisite[k][j]) {
                        isPrerequisite[i][j] = true;
                    }
                }
            }
        }

        // Answer each query based on the computed transitive closure
        vector<bool> answer;
        for (const auto& query : queries) {
            answer.push_back(isPrerequisite[query[0]][query[1]]);
        }

        return answer;
    }
};