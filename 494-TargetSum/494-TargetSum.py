# Last updated: 07/08/2025, 12:50:39
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        nums_count = len(nums)
        @cache
        def f(nums_index, target):
            if nums_index == nums_count:
                return 1 if target == 0 else 0
            plus = f(nums_index + 1, target - nums[nums_index])
            minus = f(nums_index + 1, target + nums[nums_index])
            return plus + minus

        return f(0, target)