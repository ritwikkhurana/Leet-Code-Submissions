class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n = asteroids.size();
        for (int i = 0 ; i < n ; i++) {
            int curr = asteroids[i];
            if (s.empty()) {
                s.push(curr);
            } else {
                int top = s.top();
                if (top < 0) {
                    s.push(curr);
                } else {
                    if (curr > 0) {
                        s.push(curr);
                    } else {
                        while (!s.empty() && s.top() > 0 && abs(s.top()) < abs(curr)) s.pop();
                        if (s.empty()) {
                            s.push(curr);
                        } else if (s.top() > 0 && abs(s.top()) == abs(curr)) {
                            s.pop();
                        } else if (s.top() < 0){
                            s.push(curr);
                        }
                    }
                }
            }
        }
        vector<int> output;
        while (!s.empty()) {
            output.push_back(s.top());
            s.pop();
        }
        reverse(output.begin(), output.end());
        return output;
    }
};