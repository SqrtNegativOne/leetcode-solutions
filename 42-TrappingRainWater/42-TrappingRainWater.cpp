// Last updated: 07/08/2025, 12:51:27
class Solution {
public:
    int trap(vector<int>& heights) {
        vector<int> left_max(heights.size(), 0);
        vector<int> right_max(heights.size(), 0);
        int current_max = 0;
        for (int i = 1; i < heights.size(); i++) {
            current_max = max(current_max, heights[i-1]);
            left_max[i] = current_max;
        }
        current_max = 0;
        for (int i = heights.size()-2; i >= 0; i--) {
            current_max = max(current_max, heights[i+1]);
            right_max[i] = current_max;
        }

        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            int water = min(left_max[i], right_max[i]) - heights[i];
            if (water > 0) ans += water;
        }
        return ans;
    }
};