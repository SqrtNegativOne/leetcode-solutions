# Last updated: 07/08/2025, 12:50:50
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        window = set()
        left = 0
        for right in range(len(nums)):
            right_value = nums[right]
            if right - left > k:
                window.remove(nums[left])
                left += 1
            if right_value in window:
                return True
            window.add(right_value)
        return False
            