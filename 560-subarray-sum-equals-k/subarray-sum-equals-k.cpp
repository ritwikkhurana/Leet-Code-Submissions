class Solution {
public:
    int subarraySum(vector<int>& A, int Y) {
        int n = A.size();
    unordered_map<int,int> sumCount;
    int totalSum = 0;
    int subArrayCount = 0;
    for (int i = 0 ; i < n ; i++) {
        totalSum += A[i];
        if (totalSum == Y) subArrayCount++;
        subArrayCount += (sumCount[totalSum-Y]);
        sumCount[totalSum]++;
    }
    return subArrayCount;
    }
};