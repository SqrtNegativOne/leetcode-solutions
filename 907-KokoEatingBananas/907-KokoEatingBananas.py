# Last updated: 07/08/2025, 12:50:25
def ceildiv(n: int, d: int) -> int:
    return -(n//(-d))
class Solution:
    def minEatingSpeed(self, piles: List[int], hours_limit: int) -> int:
        def allEaten(rate: int) -> bool:
            hours_taken: int = 0
            for pile in piles:
                hours_taken += ceildiv(pile, rate)
                if hours_taken > hours_limit:
                    return False
            return True
        
        l, r = 1, max(piles)
        while l<=r:
            m = l+(r-l)//2
            if allEaten(m):
                r=m-1
            else:
                l=m+1
        return l
        