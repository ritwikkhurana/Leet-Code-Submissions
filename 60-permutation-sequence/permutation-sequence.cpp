class Solution {
public:
    int getFact(int n) {
        if (n == 1 || n == 0) return 1;
        return n * getFact(n-1);
    }
    void helper(vector<int> &num, int start, int n, int rem) {
        if (rem <= 1) return;
        int currSize = n-start;
        int totalComb = getFact(currSize-1);
        int used = rem/totalComb;
        rem = rem%totalComb;
        cout << "Used: " << used <<  ", Rem: " << rem << endl;
        if (rem == 0 && used == n) {
            sort(num.begin(), num.end(),greater<int>());
        } else if (rem == 0) {
            for (int i = 0 ; i < n ; i++) {
            cout << num[i] << " ";
        }
        cout << endl;
            swap(num[start],num[start+used-1]);
            for (int i = 0 ; i < n ; i++) {
            cout << num[i] << " ";
        }
        cout << endl;
            sort(num.begin() + start + 1, num.end(),greater<int>());
            for (int i = 0 ; i < n ; i++) {
            cout << num[i] << " ";
        }
        cout << endl;
        } else {
            swap(num[start], num[start+used]);
            sort(num.begin() + start + 1, num.end());
        }
        helper(num, start+1, n, rem);
    }
    string getPermutation(int n, int k) {
        vector<int> num(n, 0);
        for (int i = 0 ; i < n ; i++) {
            num[i] = i+1;
        }
        helper(num, 0, n, k);
        string output;
        for (int i: num) {
            output.push_back('0' + i);
        }
        return output;
    }
};