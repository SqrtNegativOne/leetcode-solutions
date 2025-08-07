// Last updated: 07/08/2025, 12:51:00
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int n : nums) {
            x ^= n;
        }
        return x;
    }
};