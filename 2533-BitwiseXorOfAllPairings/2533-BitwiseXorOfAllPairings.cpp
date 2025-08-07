// Last updated: 07/08/2025, 12:49:52
class Solution {
public:
    int xorAllNums(const vector<int>& nums1, const vector<int>& nums2) {
        int answer = 0;
        if (nums1.size()&1) { // if odd
            answer ^= accumulate(nums2.begin(), nums2.end(), 0, bit_xor<>());
        }
        if (nums2.size()&1) {
            answer ^= accumulate(nums1.begin(), nums1.end(), 0, bit_xor<>());
        }

        return answer;
    }
};