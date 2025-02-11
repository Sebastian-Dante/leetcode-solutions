class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Counter for elements not equal to val

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Move valid elements to the front
                k++;
            }
        }

        return k; // Return the count of elements not equal to val
    }
};