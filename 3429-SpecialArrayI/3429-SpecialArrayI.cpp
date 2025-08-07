// Last updated: 07/08/2025, 12:49:46
class Solution {
public:
    bool isArraySpecial(const vector<int>& nums) {
        if (nums.size()==1) return true;
        for (int i = 1; i < nums.size(); i++)
            if ((nums[i]&1)==(nums[i-1]&1))
                return false;
        return true;
    }
};