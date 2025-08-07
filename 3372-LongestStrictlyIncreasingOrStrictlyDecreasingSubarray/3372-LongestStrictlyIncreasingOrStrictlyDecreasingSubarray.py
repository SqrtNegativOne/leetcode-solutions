# Last updated: 07/08/2025, 12:49:48
class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        match len(nums):
            case 1: return 1
            case 2: return 1 if nums[0]==nums[1] else 2

        longest = 1
        current = 1
        increasing = True if nums[0] < nums[1] else False
        for i in range(1, len(nums)):
            if nums[i-1] < nums[i]:
                if increasing:
                    current += 1
                else:
                    current = 2
                    increasing = True
            elif nums[i-1] > nums[i]:
                if increasing:
                    current = 2
                    increasing = False
                else:
                    current += 1
            else:
                current = 1
                increasing = False

            longest = max(current, longest)
        
        return longest