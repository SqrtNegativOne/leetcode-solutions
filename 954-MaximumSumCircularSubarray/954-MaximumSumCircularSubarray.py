# Last updated: 07/08/2025, 12:50:23
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        nums_len = len(nums)
        nums_sum = sum(nums)
        if nums_len == 1: return nums[0]
        globalMaxSum = curMaxSum = nums[0]
        globalMinSum = curMinSum = nums[0]

        for i in range(1, nums_len):
            n = nums[i]
            curMaxSum = max(curMaxSum + n, n)
            curMinSum = min(curMinSum + n, n)
            globalMaxSum = max(globalMaxSum, curMaxSum)
            globalMinSum = min(globalMinSum, curMinSum)
        
        if globalMinSum == nums_sum:
            ans = globalMaxSum
        else:
            ans = max(globalMaxSum, nums_sum - globalMinSum)
        return ans