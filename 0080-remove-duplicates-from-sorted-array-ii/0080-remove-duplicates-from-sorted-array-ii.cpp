class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If the array has less than 3 element, no need to modify it.
        if (nums.size() <= 2) return nums.size();

        // Pointer for the position to place the next allowed element.
        int index = 2;

        // Iterate over the array starting from the third element
        for (int i = 2; i < nums.size(); i++) {
            // If the current element is not equal to the element at index-2,
            // it means it has appeared at most twice, so we keep it.
            if (nums[i] != nums[index - 2]) {
                nums[index] = nums[i]; // Place the element at the correct position.
                index++; // Move the idex forward
            }
        }

        // The value of index represents the new length of the modified array.
        return index;
    }
};