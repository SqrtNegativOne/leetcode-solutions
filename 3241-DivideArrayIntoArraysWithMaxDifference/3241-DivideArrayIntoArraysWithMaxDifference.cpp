// Last updated: 07/08/2025, 12:49:49
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        for (int i = 2; i < nums.size(); i += 3) {
            if (nums[i] - nums[i-2] > k)
                return {};
        }

        vector<vector<int>> answer(nums.size()/3, vector<int>(3, 0));
        for (int i = 0; i < nums.size(); i++) {
            answer[i/3][i%3] = nums[i];
        }

        return answer;
    }
};