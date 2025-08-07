// Last updated: 07/08/2025, 12:50:10
class Solution {
public:
    int tupleSameProduct(const vector<int>& nums) {
        const int N = nums.size();

        std::unordered_map<int, int> product_frequency = {};
        product_frequency.reserve(N * (N - 1) / 2);
        int answer = 0;

        for (int i1 = 0; i1 < N; i1++)
        for (int i2 = i1+1; i2 < N; i2++) {
            const int n1 = nums[i1], n2 = nums[i2], product = n1 * n2;
            answer += product_frequency[product];
            product_frequency[product]++;
        }

        return answer * 8;
    }
};