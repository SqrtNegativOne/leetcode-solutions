// Last updated: 07/08/2025, 12:50:32
class Solution {
public:
    vector<int> asteroidCollision(const vector<int>& asteroids) {
        vector<int> after_collision;
        after_collision.reserve(asteroids.size());
        for (const int& asteroid : asteroids) {
            bool asteroid_broken = false;
            while (!after_collision.empty() and after_collision.back() > 0 and asteroid < 0) {
                if (-asteroid < after_collision.back()) {
                    asteroid_broken = true;
                    break;
                } else if (-asteroid == after_collision.back()) {
                    after_collision.pop_back();
                    asteroid_broken = true;
                    break;
                } else {
                    after_collision.pop_back();
                }
            }
            if (asteroid_broken) continue;
            after_collision.push_back(asteroid);
        }
        after_collision.shrink_to_fit();
        return after_collision;
    }
};