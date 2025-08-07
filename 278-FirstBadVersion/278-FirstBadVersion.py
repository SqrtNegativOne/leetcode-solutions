# Last updated: 07/08/2025, 12:50:46
# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        l, r = 1, n
        while l<=r:
            possible_answer = l+(r-l)//2
            if isBadVersion(possible_answer):
                r = possible_answer-1
            else:
                l = possible_answer+1
        return l
        