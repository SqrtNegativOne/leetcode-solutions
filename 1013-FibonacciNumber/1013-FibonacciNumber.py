# Last updated: 07/08/2025, 12:50:20
class Solution:
    def fib(self, n: int) -> int:
        if n <= 1:
            return n

        dp_i_minus_2 = 0
        dp_i_minus_1 = 1
        dp_i = 1
        for i in range(2, n+1):
            dp_i = dp_i_minus_1 + dp_i_minus_2
            dp_i_minus_2 = dp_i_minus_1
            dp_i_minus_1 = dp_i

        return dp_i