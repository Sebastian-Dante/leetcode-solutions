class Solution {
public:
    bool check(vector<int>& nums) {

        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Check if current element is greater than the next ( considering swap)
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            // If we have more than one decrease, it's not a rotated sorted array
            if (count > 1) {
                return false;
            }
        }
        return true;
        
    }
};