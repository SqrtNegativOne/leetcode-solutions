# Last updated: 07/08/2025, 12:50:53
class Solution:
    def rob(self, nums: List[int]) -> int:
        nums_count = len(nums)
        match nums_count:
            case 1:
                return nums[0]
            case 2:
                return max(nums[0], nums[1])
            case 3:
                return max(nums[0] + nums[2], nums[1])

        dp_i = 0
        dp_i_plus_1 = max(nums[-3] + nums[-1], nums[-2])
        dp_i_plus_2 = max(nums[-2], nums[-1])
        dp_i_plus_3 = nums[-1]

        for house_index in range(nums_count-4, -1, -1):
            dp_i = max(nums[house_index] + dp_i_plus_2, nums[house_index+1] + dp_i_plus_3)
            dp_i_plus_1, dp_i_plus_2, dp_i_plus_3 = dp_i, dp_i_plus_1, dp_i_plus_2
        
        return dp_i