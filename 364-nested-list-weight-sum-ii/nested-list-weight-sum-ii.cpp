/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    void getMaxDepth(vector<NestedInteger>& nestedList, int depth, int &maxDepth) {
        if (nestedList.size() == 0) return;
        maxDepth = max(maxDepth, depth);
        for (int i = 0 ; i < nestedList.size() ; i++) {
            if (nestedList[i].isInteger()) continue;
            getMaxDepth(nestedList[i].getList(), depth+1, maxDepth);
        }
    }
    void calWeight(vector<NestedInteger>& nestedList, int depth, int &totalWeight, int &maxDepth) {
        for (int i = 0 ; i < nestedList.size() ; i++) {
            if (nestedList[i].isInteger()) {
                totalWeight += ((maxDepth-depth+1) * nestedList[i].getInteger());
            } else {
                calWeight(nestedList[i].getList(), depth+1, totalWeight, maxDepth);
            }
        }
    }
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = 0;
        int n = nestedList.size();
        int totalWeight = 0;
        int maxDepth = 0;
        getMaxDepth(nestedList, 1, maxDepth);
        calWeight(nestedList, 1, totalWeight, maxDepth);
        return totalWeight;
    }
};