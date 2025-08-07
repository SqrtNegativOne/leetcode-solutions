# Last updated: 07/08/2025, 12:50:07
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        def condition(divisor) -> bool:
            return sum(-(v//(-divisor)) for v in nums) <= threshold
        
        l, r = 1, max(nums)+1
        while l<=r:
            m = l+(r-l)//2
            if condition(m):
                r=m-1
            else:
                l=m+1

        return l