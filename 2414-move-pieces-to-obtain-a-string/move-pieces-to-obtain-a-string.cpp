class Solution {
public:
    bool canChange(string start, string target) {
        stack<char> pos;
        int n = start.size();
        for (int i = 0 ; i < n ; i++) {
            if (start[i] == 'R' && target[i] == '_') {
                pos.push('R');
            } else if (start[i] == '_' && target[i] == 'L') {
                pos.push('L');
            } else if (start[i] == '_' && target[i] == 'R') {
                if (pos.empty() || pos.top() == 'L') return false;
                pos.pop();
            } else if (start[i] == 'L' && target[i] == '_'){
                if (pos.empty() || pos.top() == 'R') return false;
                pos.pop();
            } else if (start[i] == target[i] && start[i] != '_' && !pos.empty() && pos.top() != start[i]) {
                return false;
            } else if (start[i] != target[i]) return false;
        }
        return pos.empty();
    }
};