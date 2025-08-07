# Last updated: 07/08/2025, 12:50:15
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        prev_i_max = 0
        max_score = 0
        for i, n in enumerate(values):
            current_j = n-i
            max_score = max(max_score, prev_i_max + current_j)
            prev_i_max = max(prev_i_max, n+i)
        return max_score