class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int k = 1; // Pointer for unique elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { // Found a new unique element
                nums[k] = nums[i]; // Move it to the front
                k++;
            }
        }
        return k;
    }
};