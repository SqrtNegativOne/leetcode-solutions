# Last updated: 07/08/2025, 12:50:12
class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        def countSmallerOrEqualUglyNumbers(mid):
            return mid//a + mid//b + mid//c \
                   - mid//math.lcm(a,b) - mid//math.lcm(b,c) - mid//math.lcm(c,a) \
                   + mid//math.lcm(a,b,c)
        
        smallest = min(a,b,c)
        l, r = smallest, smallest*n
        while l<=r:
            mid = l+(r-l)//2
            temp = countSmallerOrEqualUglyNumbers(mid)
            if temp < n:
                l=mid+1
            else:
                r=mid-1
        return l