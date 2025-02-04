class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1; // Last element nums1's actual values
        int j = n - 1; // Last element of nums2
        int k = m + n - 1; // Last position in nums1 

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // If there are remaining elements in nums2, copy them over
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
        
    }
};