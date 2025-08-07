// Last updated: 07/08/2025, 12:50:36
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> answer(nums.size(), -1);

        for (int i = nums.size()-1; i >= 0; i--) {
            while (!s.empty() && nums[i] >= s.top()) {
                s.pop();
            }
            if (!s.empty()) {
                answer[i] = s.top();
            }
            s.push(nums[i]);
        }
        for (int i = nums.size()-1; i >= 0; i--) {
            while (!s.empty() && nums[i] >= s.top()) {
                s.pop();
            }
            if (!s.empty()) {
                answer[i] = s.top();
            }
            s.push(nums[i]);
        }
        return answer;
    }
};