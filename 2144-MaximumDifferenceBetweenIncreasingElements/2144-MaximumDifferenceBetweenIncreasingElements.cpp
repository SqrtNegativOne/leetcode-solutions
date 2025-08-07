// Last updated: 07/08/2025, 12:49:59
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDifference = 0;
        int smallestInteger = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < smallestInteger) {
                smallestInteger = nums[i];
            } else {
                int difference = nums[i] - smallestInteger;
                if (difference > maxDifference)
                    maxDifference = difference;
            }
        }

        if (maxDifference <= 0) return -1;
        return maxDifference;
    }
};