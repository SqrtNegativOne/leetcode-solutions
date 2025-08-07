# Last updated: 07/08/2025, 12:51:33
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        for i in range(size - 2, -1, -1):
            v = nums[i]
            prev_v = nums[i+1]

            if prev_v > v:
                min_prev_v = prev_v
                min_prev_i = i+1
                for j in range(size-1, i+1, -1):
                    current_v = nums[j]
                    if current_v > v and current_v < min_prev_v:
                        min_prev_v = current_v
                        min_prev_i = j
                print(v, i, min_prev_v)

                print(nums)
                nums[i] = min_prev_v
                nums[min_prev_i] = v
                print(nums)

                nums[i+1:] = sorted(nums[i+1:])
                break
        else: # nobreak
            nums.reverse()