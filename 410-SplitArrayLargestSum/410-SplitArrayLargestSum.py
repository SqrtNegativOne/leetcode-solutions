# Last updated: 07/08/2025, 12:50:44
def ceildiv(n, d):
    return -(n//(-d))

class Solution:
    def splitArray(self, nums: List[int], max_sections: int) -> int:
        nums_max = max(nums)
        nums_count = len(nums)

        def feasible(capacity):
            cur_sum = 0
            cur_section = 1
            for n in nums:
                cur_sum += n
                if cur_sum > capacity:
                    cur_sum = n
                    cur_section += 1
                    if cur_section > max_sections:
                        return False
            return True
        
        l, r = nums_max, nums_max*ceildiv(nums_count, max_sections)
        while l<=r:
            m = l+(r-l)//2
            if feasible(m):
                r=m-1
            else:
                l=m+1
        return l