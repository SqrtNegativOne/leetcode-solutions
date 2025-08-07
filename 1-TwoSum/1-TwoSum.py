# Last updated: 07/08/2025, 12:51:41
class Solution:
    def twoSum(self, arr: List[int], target: int) -> List[int]:
        seen = {}
        for i, v in enumerate(arr):
            complement = target - v
            if complement in seen:
                return [i, seen[complement]]
            seen[v] = i
        return []