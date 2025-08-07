# Last updated: 07/08/2025, 12:50:05
class Solution:
    def minDays(self, bloomDay: List[int], bouquets_req: int, flowers_req: int) -> int:
        def feasible(days):
            cur_flowers = 0
            cur_bouquets = 0
            for v in bloomDay:
                if days < v:
                    cur_flowers = 0
                    continue
                cur_flowers += 1
                if cur_flowers == flowers_req:
                    cur_flowers = 0
                    cur_bouquets += 1
            print(days, cur_bouquets)
            return cur_bouquets >= bouquets_req
        
        max_days = max(bloomDay)
        l, r = 1, max_days
        while l<=r:
            m = l+(r-l)//2
            if feasible(m):
                r=m-1
            else:
                l=m+1
        if l > max_days: return -1
        return l