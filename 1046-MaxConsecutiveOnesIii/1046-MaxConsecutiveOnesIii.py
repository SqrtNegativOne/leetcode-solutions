# Last updated: 07/08/2025, 12:50:18
class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        nums_len = len(nums)
        l, r = 0, 0
        cur_k = 0
        max_consecutive = 0
        while r < nums_len:
            if nums[r] == 0:
                cur_k += 1
            if cur_k > k:
                # Shrink the window
                while nums[l] != 0:
                    l += 1
                l += 1
                cur_k -= 1
            max_consecutive = max(r-l+1, max_consecutive)
            r += 1
        return max_consecutive