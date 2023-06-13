class Solution:
    """
    @param nums: An integer array sorted in ascending order
    @param target: An integer
    @return: An integer
    """
    def findPosition(self, nums, target):
        # write your code here
        return self.binary_search(0, len(nums)-1, nums, target)

    def binary_search(self, start, end, nums, target):
        if start > end:
            return -1
        mid = (start + end) // 2
        if nums[mid] == target:
            return mid
        if nums[mid] < target:
            return self.binary_search(mid+1, end, nums, target)
        return self.binary_search(0, mid-1, nums, target)