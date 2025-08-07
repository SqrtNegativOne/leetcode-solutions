# Last updated: 07/08/2025, 12:51:02
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        for i in range(len(prices)-1):
            profit += max(0, prices[i+1] - prices[i])
        return profit