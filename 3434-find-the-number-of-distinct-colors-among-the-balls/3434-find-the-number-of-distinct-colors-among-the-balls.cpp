class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor; // Stores the color of each ball
        unordered_set<int> uniqueColors; // Stores distinct colors used
        vector<int> result;

        for (auto& query: queries) {
            int ball = query[0], color = query[1];

            // If the ball already has a color, we need to check if it changes
            if (ballColor.find(ball) != ballColor.end()) {
                int oldColor = ballColor[ball];
                //remove old color if it's no longer used
                bool stillExists = false;
                for (auto& kv: ballColor) {
                    if (kv.second == oldColor && kv.first != ball) {
                        stillExists = true;
                        break;
                    }
                }
                if (!stillExists) {
                    uniqueColors.erase(oldColor);
                }
            }

            // Assign new Color
            ballColor[ball] = color;
            uniqueColors.insert(color);

            // Store the number of unique colors in result
            result.push_back(uniqueColors.size());

        }

        return result;
    }
};