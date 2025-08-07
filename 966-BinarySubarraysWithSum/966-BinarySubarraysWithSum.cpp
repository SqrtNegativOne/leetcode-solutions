// Last updated: 07/08/2025, 12:50:22
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0;
        int cur_sum = 0;
        int cur_total_sum = 0;
        int answer = 0;

        for (int r = 0; r < n; r++) {
            cur_total_sum += nums[r];
            cur_sum = cur_total_sum;
            l = 0;
            while (cur_sum > goal && l <= r) {
                cur_sum -= nums[l++];
            }
            while (cur_sum == goal && l <= r) {
                answer++;
                //std::cout << l << ' ' << r << '\n';
                cur_sum -= nums[l++];
            }
        }

        return answer;
    }
};