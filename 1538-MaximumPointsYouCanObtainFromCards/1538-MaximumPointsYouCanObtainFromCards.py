# Last updated: 07/08/2025, 12:50:06
class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        cardCount = len(cardPoints)
        totalSum = sum(cardPoints)
        if cardCount == k: return totalSum

        # We want to minimise the sum of an sliding window in the middle.
        minSum = totalSum
        windowSize = cardCount - k
        curSum = sum(cardPoints[i] for i in range(0, windowSize))
        for i in range(windowSize, cardCount):
            minSum = min(minSum, curSum)
            curSum -= cardPoints[i - windowSize]
            curSum += cardPoints[i]
        minSum = min(minSum, curSum)
        
        return totalSum - minSum
