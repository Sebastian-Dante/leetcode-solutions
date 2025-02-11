class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int count = 0;
        int n = nums.size();

        // Store all product pairs in the hash map
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }

        // Compute the valid tuples based on product counts
        for (auto& [product, freq] : productCount) {
            if (freq > 1) {
                count += (freq * (freq - 1)) * 4; // Each pair contributes to 4 permutations
            }
        }

        return count;
        
    }
};