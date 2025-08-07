// Last updated: 07/08/2025, 12:51:30
class Solution {
private:
    int firstPosition(const vector<int>& nums, const int target) {
        int l = 0;
        int r = nums.size()-1;
        while (l<=r) {
            int m = l + (r-l) / 2;
            if (nums[m] < target) l = m+1;
            else r = m-1;
        }
        return l;
    }
    int lastPosition(const vector<int>& nums, const int target) {
        int l = 0;
        int r = nums.size()-1;
        while (l<=r) {
            int m = l + (r-l) / 2;
            if (nums[m] > target) r = m-1;
            else l=m+1;
        }
        return r;
    }
public:
    vector<int> searchRange(const vector<int>& nums, const int target) {
        int first_position = firstPosition(nums, target);
        if (not nums.empty() and first_position != nums.size() and nums[first_position] == target) {
            return {first_position, lastPosition(nums, target)};
        }
        return {-1, -1};
    }
};