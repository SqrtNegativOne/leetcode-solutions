// Last updated: 07/08/2025, 12:51:11
class Solution {
private:
    vector<vector<int>> generateSubsets(const vector<int>& nums, int r) {
        switch (r) {
            case -1: return {{}};
            case  0: return {{}, {nums[0]}};
        }
        vector<vector<int>> answer = generateSubsets(nums, r-1);
        const int smaller_subsets_count = answer.size();
        for (int i = 0; i < smaller_subsets_count; i++) {
            vector<int> subset = answer[i];
            subset.push_back(nums[r]);
            answer.push_back(subset);
        }
        return answer;
    }
public:
    vector<vector<int>> subsets(const vector<int>& nums) {
        return generateSubsets(nums, nums.size()-1);
    }
};