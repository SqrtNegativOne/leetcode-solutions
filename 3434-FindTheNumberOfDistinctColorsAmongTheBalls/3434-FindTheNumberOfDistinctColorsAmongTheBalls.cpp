// Last updated: 07/08/2025, 12:49:39
class Solution {
public:
    vector<int> queryResults(const int limit, const vector<vector<int>>& queries) {
        const int N = queries.size();

        unordered_map<int, int> color_count = {};
        color_count.reserve(N);
        unordered_map<int, int> ball_color = {};
        ball_color.reserve(N);

        int unique_color_count = 0;

        vector<int> result = {};
        result.reserve(N);

        for (auto& query : queries) {
            const int ball = query[0];
            const int color = query[1];

            if (ball_color.contains(ball)) {
                color_count[ball_color[ball]]--;
                if (color_count[ball_color[ball]] == 0)
                    unique_color_count--;
            }
            if (not color_count.contains(color) or color_count[color] == 0)
                unique_color_count++;
            color_count[color]++;
            ball_color[ball] = color;

            result.push_back(unique_color_count);
        }

        return result;
    }
};

// check if new ball is there
// if new ball there, change new balls color
// if no other ball has that color, remove color from color_set
// how to check if no other ball has that color very fast