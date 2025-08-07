# Last updated: 07/08/2025, 12:50:01
class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        answer = nums[0]
        current = nums[0]
        for i in range(1, len(nums)):
            if nums[i-1] < nums[i]:
                current += nums[i]
            else:
                current = nums[i]
            answer = max(current, answer)
    
        return answer