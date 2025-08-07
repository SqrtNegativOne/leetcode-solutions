// Last updated: 07/08/2025, 12:51:20
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int closest_index = nums.size()-1;
        for (int i = nums.size()-2; i >= 0; i--) {
            if (nums[i] >= closest_index - i)
                closest_index = i;
        }
        return closest_index == 0;
    }
};