class Solution {
public:
    int jump(vector<int>& jump) {
       int size = jump.size();
	int jumps = 0;
	int maxReach = 0;
	int lastReach = jump[0];
    if (size == 1) return 0;
    int index = 1;
while (index < size-1) {
    maxReach = max(maxReach, index+jump[index]);
    if (lastReach == index) {
        jumps++;
        if (lastReach == maxReach) return -1;
        lastReach = maxReach;
    }
    index++;
}
if (lastReach >= size-1) jumps++;
return jumps;
}

};