# Last updated: 07/08/2025, 12:51:42
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest_length = 0
        current_substring = ''
        start_index = 0
        s_length = len(s)

        i = 0
        while i < s_length:
            c = s[i]
            if c in current_substring:
                if (current_length:=len(current_substring)) > longest_length:
                    longest_length = current_length
                
                i = start_index + current_substring.find(c) + 1
                current_substring = s[i]
                start_index = i
            else:
                current_substring += c
            
            i += 1
        
        if (current_length:=len(current_substring)) > longest_length:
            longest_length = current_length

        return longest_length