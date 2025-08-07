# Last updated: 07/08/2025, 12:49:42
class Solution:
    def compressedString(self, word: str) -> str:
        prev_c = ''
        cur_prefix = 0
        comp = ''
        for c in word:
            if c == prev_c:
                cur_prefix += 1
                continue
            
            while cur_prefix != 0:
                if cur_prefix <= 9:
                    comp += str(cur_prefix) + prev_c
                    cur_prefix = 0
                else:
                    comp += '9' + prev_c
                    cur_prefix -= 9
            prev_c = c
            cur_prefix = 1
        
        while cur_prefix != 0:
            if cur_prefix <= 9:
                comp += str(cur_prefix) + prev_c
                cur_prefix = 0
            else:
                comp += '9' + prev_c
                cur_prefix -= 9
        
        return comp