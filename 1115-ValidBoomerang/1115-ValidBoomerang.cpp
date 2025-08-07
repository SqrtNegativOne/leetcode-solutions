// Last updated: 07/08/2025, 12:50:13
class Solution {
public:
    bool isBoomerang(const vector<vector<int>>& points) {
        const int x1 = points[0][0], y1 = points[0][1];
        const int x2 = points[1][0], y2 = points[1][1];
        const int x3 = points[2][0], y3 = points[2][1];
    
        return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) != 0;
    }
};