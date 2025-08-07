# Last updated: 07/08/2025, 12:51:14
class Solution:
    def mySqrt(self, x: int) -> int:
        def condition(m):
            return m**2 > x

        l, r = 0, x
        while l<=r:
            m = l+(r-l)//2
            if condition(m):
                r = m-1
            else:
                l = m+1
        
        return l-1