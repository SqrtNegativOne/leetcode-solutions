// Last updated: 07/08/2025, 12:50:37
#include <ranges>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        std::unordered_set<int> nums1set(nums1.begin(), nums1.end());
        vector<int> answers(nums1.size(), -1);
        
        int lastElement = nums2[nums2.size()-1];
        s.push(lastElement);
        if (nums1set.count(lastElement)) {
            auto it = find(nums1.begin(), nums1.end(), lastElement);
            int index = distance(nums1.begin(), it);
            answers[index] = -1;
        }
        
        for (int& v : nums2 | std::views::reverse | std::views::drop(1)) {
            while (!s.empty() && v >= s.top()) {
                s.pop();
            }
            if (!s.empty() && nums1set.count(v)) {
                auto it = find(nums1.begin(), nums1.end(), v);
                int index = distance(nums1.begin(), it);
                answers[index] = s.top();
            }
            s.push(v);
        }
        return answers;
    }
};