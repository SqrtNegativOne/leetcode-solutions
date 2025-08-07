# Last updated: 07/08/2025, 12:50:33
class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        min_so_far = arrays[0][0]
        max_so_far = arrays[0][-1]
        max_dist_so_far = 0
        for array in arrays[1:]:
            max_dist_so_far = max(
                max_dist_so_far,
                abs(array[-1] - min_so_far),
                abs(max_so_far - array[0])
            )
            min_so_far = min(min_so_far, array[0])
            max_so_far = max(max_so_far, array[-1])
        return max_dist_so_far