// Last updated: 07/08/2025, 12:49:55
class Solution {
public:
    long long countBadPairs(const vector<int>& nums) {

        const long N = nums.size();

        long good_pair_count = 0;

        unordered_map<int, int> num_i_count = {};
        num_i_count.reserve(N);

        for (int i = 0; i < N; i++) {
            const int num_i = nums[i] - i;

            good_pair_count += num_i_count[num_i];
            
            num_i_count[num_i]++;
        }

        return N*(N-1)/2 - good_pair_count;
    }
};