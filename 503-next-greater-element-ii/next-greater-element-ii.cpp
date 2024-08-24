class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> circ(nums);
        circ.insert(circ.end(), nums.begin(), nums.end()-1);
        stack<int> s;
        vector<int> output;
        for (int i = circ.size()-1 ; i>=0 ; i--) {
            while (!s.empty() && s.top() <= circ[i]) s.pop();
            if (i < n) {
                if (s.empty()) {
                    output.push_back(-1);
                } else {
                    output.push_back(s.top());
                }
            }
            s.push(circ[i]);
        }
        reverse(output.begin(), output.end());
        return output;
    }
};