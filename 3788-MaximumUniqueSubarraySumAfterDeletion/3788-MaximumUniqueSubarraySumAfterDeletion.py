# Last updated: 07/08/2025, 12:49:41
class Solution:
    def maxSum(self, nums: List[int]) -> int:
        nums = set(nums)
        ans = sum(n for n in nums if n > 0)
        if ans == 0:
            return max(nums)
        return ans
            