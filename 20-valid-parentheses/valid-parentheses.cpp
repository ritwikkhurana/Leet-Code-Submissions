class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> brackets = {{'(',')'},{'{','}'},{'[',']'}};
        stack<char> st;
        for (char c : s) {
            if (brackets.find(c) != brackets.end()) {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                if (brackets[top] != c) return false;
                st.pop();
            }
        }
        if (!st.empty()) return false;
        return true;
    }
};