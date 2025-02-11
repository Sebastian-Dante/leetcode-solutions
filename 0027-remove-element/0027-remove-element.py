class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0 # Counter for elements not equal to val

        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i] # Move valid elements to the front
                k += 1

        return k # Return the count of elements not equal to val