class Solution {
public:
    string decodeString(string s) {
       stack<string> str;
       stack<int> num;
       string currString = "";
       int currNum = 0;
       for (char c: s) {
        if (isdigit(c)) {
            currNum = (currNum * 10) + (c -'0');
        } else if (c == '[') {
            str.push(currString);
            currString = "";
            num.push(currNum);
            currNum = 0;
        } else if (c == ']') {
            int number = num.top();num.pop();
            string temp = "";
            for (int i = 0 ; i < number ; i++) {
                temp += currString;
            }
            currString = temp;
            currString = str.top() + currString;
            str.pop();
        } else {
            currString.push_back(c);
        }
       }
       return currString; 
       }
};