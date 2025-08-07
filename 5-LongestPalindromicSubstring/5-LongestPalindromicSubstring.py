# Last updated: 07/08/2025, 12:51:37
class Solution:
    def longestPalindrome(self, s: str) -> str:
        L, R = 1, 1
        s_len = len(s)
        s = '^' + s + '$'

        for l in range(1, s_len+1):
            r = l
            while s[l-1] == s[r+1]:
                l -= 1
                r += 1
            if r-l+1 > R-L+1:
                L, R = l, r

        for l in range(1, s_len+1):
            r = l+1
            if s[l] != s[r]: continue
            print(l, r, L, R)
            while l>=1 and r<=s_len and s[l-1] == s[r+1]:
                l -= 1
                r += 1
            if r-l+1 > R-L+1:
                L, R = l, r

        return s[L:R+1]