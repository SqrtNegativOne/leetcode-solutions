// Last updated: 07/08/2025, 12:50:41
class Solution {
private:
    int characterReplacementWithChar(const string& s, const int& k, const char& c) {
        int left = 0;
        int cur_k = k;
        int answer = 0;
        for (int right = 0; right < s.size(); right++) {
            if (s[right] != c) {
                cur_k--;
                while (cur_k < 0) {
                    if (s[left] != c) {
                        cur_k++;
                    }
                    left++;
                }
            }
            answer = std::max(right-left+1, answer);
        }
        return answer;
    }
public:
    int characterReplacement(const string& s, const int& k) {
        int answer = 0;
        std:unordered_set<char> searched_letters{};
        for (const char c: s) {
            if (searched_letters.contains(c)) continue;
            answer = max(answer, characterReplacementWithChar(s, k, c));
            searched_letters.insert(c);
        }
        return answer;
    }
};