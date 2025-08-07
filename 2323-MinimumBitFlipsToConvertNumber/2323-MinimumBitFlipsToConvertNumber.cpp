// Last updated: 07/08/2025, 12:49:58
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        int count = 0;
        for (int x = n; x; x &= (x-1)) count++;
        return count;
    }
};