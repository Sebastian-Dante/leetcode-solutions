class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long total_pairs = (n * (n -1)) / 2; // Total pair (i, j) where i < j

        unordered_map<int, long long> count_map;
        long long good_pairs = 0;

        for (int j = 0; j < n; ++j) {
            int key = nums[j] - j;
            if (count_map.find(key) != count_map.end()) {
                good_pairs += count_map[key];
            }
            count_map[key]++;
        }

        return total_pairs - good_pairs;
    }
};