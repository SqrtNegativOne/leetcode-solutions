# Last updated: 07/08/2025, 12:49:51
class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        # 100 00 ; 99 99
        i = low
        answer = 0
        while i <= high:
            n = i
            n, first_digit  = divmod(n, 10)
            n, second_digit = divmod(n, 10)
            n, third_digit  = divmod(n, 10)
            n, fourth_digit = divmod(n, 10)

            two_digits = fourth_digit == 0 and third_digit == 0 and second_digit != 0
            four_digits = fourth_digit != 0

            if two_digits:
                answer += first_digit == second_digit
            elif four_digits:
                answer += first_digit + second_digit == third_digit + fourth_digit
            
            i += 1
        
        return answer