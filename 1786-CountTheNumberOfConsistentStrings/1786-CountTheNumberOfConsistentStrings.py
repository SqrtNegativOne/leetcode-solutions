# Last updated: 07/08/2025, 12:50:03
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        allowed = set(i for i in allowed)
        answer = 0
        for word in words:
            flag = True
            for letter in word:
                print(word, letter)
                if letter not in allowed:
                    flag = False
                    break
            if not flag: continue
            answer += 1
        
        return answer
