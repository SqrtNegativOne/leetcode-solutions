// Last updated: 07/08/2025, 12:51:38
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> current_substring = {};
        int answer = 0;
        int l = 0; int r = 0;
        for (char c : s) {
            while (current_substring.contains(c)) {
                current_substring.erase(s[l++]);
            }
            current_substring.insert(c);
            r++;
            answer = max(answer, r-l);
        }
        return answer;
    }
};

static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();