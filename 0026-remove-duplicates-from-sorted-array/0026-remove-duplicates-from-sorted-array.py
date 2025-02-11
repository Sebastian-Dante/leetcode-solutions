class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0

        k = 1 # Pointer for the unique elements index
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]: # If a new unique element is found
                nums[k] = nums[i] # Move it to the front
                k += 1 # Increment unique elements count
        
        return k
        