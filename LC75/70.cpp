//735. Asteroid Collision
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> dummy;
        for (int i = 0; i < asteroids.size(); i++) {
            if (dummy.empty()) {
                dummy.push(asteroids[i]);
            }
            else if (asteroids[i] < 0 && dummy.top() > 0) {
                if (abs(asteroids[i]) > abs(dummy.top())) {
                    dummy.pop();
                    i--;
                }
                else if (abs(asteroids[i]) == abs(dummy.top())) {
                    dummy.pop();
                }
            }
            else {
                dummy.push(asteroids[i]);
            }
        }

        asteroids.clear();
        while (!dummy.empty()) {
            asteroids.push_back(dummy.top());
            dummy.pop();
        }
        reverse(asteroids.begin(), asteroids.end());
        return asteroids;
    }
};