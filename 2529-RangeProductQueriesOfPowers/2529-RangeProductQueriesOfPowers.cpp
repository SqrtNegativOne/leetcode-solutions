// Last updated: 11/08/2025, 16:27:14
class Solution {
public:
    vector<int> productQueries(int n, const vector<vector<int>>& queries) {
        vector<int> arr;
        for (int bit = 0; n; n=n>>1, ++bit) {
            if (n&1) arr.push_back(bit);
        }

        for (size_t i = 1; i < arr.size(); i++)
            arr[i] += arr[i-1];
        
        vector<int> ans_powers;
        ans_powers.reserve(queries.size());
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            if (l==0) ans_powers.push_back(arr[r]);
            else ans_powers.push_back(arr[r]-arr[l-1]);
        }

        const int MOD = 1'000'000'007;
        auto mod_pow = [&](long long base, long long exp, long long mod) {
            long long result = 1;
            while (exp > 0) {
                if (exp & 1) result = (result * base) % mod;
                base = (base * base) % mod;
                exp >>= 1;
            }
            return result;
        };
        vector<int> ans;
        ans.reserve(ans_powers.size());
        for (const int i : ans_powers)
            ans.push_back(mod_pow(2, i, MOD));
        
        return ans;
    }
};