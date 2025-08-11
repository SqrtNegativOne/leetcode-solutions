// Last updated: 11/08/2025, 16:27:45
class Solution {
public:
    bool isPowerOfTwo(long long n) {
        if (n==0) return false;
        return (n & n - 1) == 0;
    }
};