// Last updated: 07/08/2025, 12:50:47
class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, const int& target) {
        int x = matrix[0].size()-1; int y = 0;
        while (x >= 0 and y < matrix.size()) {
            const int c = matrix[y][x];
            if (target > c) y++;
            else if (target < c) x--;
            else return true;
        }
        return false;
    }
};

static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();