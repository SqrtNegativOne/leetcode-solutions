# Last updated: 07/08/2025, 12:50:40
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        s_len = len(s)
        s_ptr = 0
        content = 0
        for greed in g:
            while s_ptr != s_len and s[s_ptr] < greed:
                s_ptr += 1
            if s_ptr == s_len:
                break
            if s[s_ptr] >= greed:
                s_ptr += 1
                content += 1
                continue # Move on to the next child
        
        return content
