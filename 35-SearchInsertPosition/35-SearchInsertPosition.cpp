// Last updated: 07/08/2025, 12:51:29
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0; int r = n - 1;
        int m = -1;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (target > nums[m]) {
                l = m + 1;
            } else if (target < nums[m]) {
                r = m - 1;
            } else {
                return m;
            }
        }
        if (m == n) return n;
        if (target < nums[m]) {
            return m;
        } else {
            return m + 1; 
        }
    }
};