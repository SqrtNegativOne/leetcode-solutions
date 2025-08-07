// Last updated: 07/08/2025, 12:51:23
class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        int current_sum = nums[0];
        int max_sum = nums[0];
        int L = 0; int R = 0;
        int l = 0;
        for (int r = 1; r < nums.size(); r++) {
            current_sum += nums[r];
            if (nums[r] >= current_sum) {
                current_sum = nums[r];
                l = r;
            }

            if (current_sum > max_sum) {
                L = l; R = r;
                max_sum = current_sum;
            }
        }
        std::cout << L << ' ' << R;
        return max_sum;
    }
};