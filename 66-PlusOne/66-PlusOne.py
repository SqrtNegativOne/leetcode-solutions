# Last updated: 07/08/2025, 12:51:15
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits_count = len(digits)
        last_digit = digits_count - 1
        answer = digits
        while digits[last_digit] == 9:
            answer[last_digit] = 0
            last_digit -= 1
            if last_digit < 0:
                return [1] + [0] * digits_count
        answer[last_digit] += 1
        return answer