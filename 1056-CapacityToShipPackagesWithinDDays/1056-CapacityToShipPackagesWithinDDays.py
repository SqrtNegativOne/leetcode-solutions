# Last updated: 07/08/2025, 12:50:16
class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        weights_count = len(weights)
        max_weight = max(weights)
        def condition(capacity):
            cur_sum = 0
            cur_day = 1
            for i in range(weights_count):
                cur_sum += weights[i]
                if cur_sum > capacity:
                    cur_sum = weights[i]
                    cur_day += 1
                    if cur_day > days: return False
            return True

        l, r = max_weight, int(max_weight * -(weights_count // (-days)))
        while l<=r:
            m = l+(r-l)//2
            if condition(m):
                r = m-1
            else:
                l = m+1
        return int(l)