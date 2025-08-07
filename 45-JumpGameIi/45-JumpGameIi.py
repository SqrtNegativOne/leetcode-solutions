# Last updated: 07/08/2025, 12:51:26
class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        cur = 0
        ans = 0
        while True:
            if cur + nums[cur] >= len(nums)-1:
                ans += 1
                return ans

            best_pos = 0
            best_close = 0
            for i in range(cur+1, cur+1+nums[cur]):
                if nums[i] + i > best_close:
                    best_close = nums[i] + i
                    best_pos = i
            
            cur = best_pos
            ans += 1