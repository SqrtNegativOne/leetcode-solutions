# Last updated: 07/08/2025, 12:51:35
class Solution:
    def maxArea(self, heights: list[int]) -> int:

        left_pointer = 0
        right_pointer = len(heights) - 1

        max_water_volume = float('-inf')
        while left_pointer != right_pointer:
            left_height = heights[left_pointer]
            right_height = heights[right_pointer]
            water_volume = (right_pointer - left_pointer) * min(left_height, right_height)
            max_water_volume = max(water_volume, max_water_volume)
            
            if left_height <= right_height:
                left_pointer += 1
            else:
                right_pointer -= 1
        
        return max_water_volume