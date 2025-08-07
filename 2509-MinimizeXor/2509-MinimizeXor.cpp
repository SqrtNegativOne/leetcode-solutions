// Last updated: 07/08/2025, 12:49:54
class Solution {
private:
    int countSetBits(const int& n) {
        int count = 0;
        for (int x = n; x; x &= (x-1)) count++;
        return count;
    }
    int getMSB(const int &n) {
        if (n==0) return 0;
        return  1<<(31 - __builtin_clz(n));
    }
public:
    int minimizeXor(int num1, const int& num2) {
        int set_bits_in_result = countSetBits(num2);
        int result = 0;

        while (set_bits_in_result > 0 and num1 != 0) {
            int msb = getMSB(num1);
            result |= msb;
            num1 ^= msb;
            set_bits_in_result--;
        }
        cout << result << ' ' << set_bits_in_result << ' ' << num1 << '\n';
        int i = 0;
        while (set_bits_in_result > 0) {
            cout << result << ' ' << set_bits_in_result << ' ' << i << '\n';
            while ((result&(1<<i)) != 0) i++;
            result ^= 1<<i;
            i++;
            set_bits_in_result--;
        }
        return result;
    }
};