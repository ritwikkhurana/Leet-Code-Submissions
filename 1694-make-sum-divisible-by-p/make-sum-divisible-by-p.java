class Solution {
    public int minSubarray(int[] nums, int p) {
        long sum = 0;
        for(int num : nums){
            sum = (sum+num)%p;
        }
        
        int rem = (int)sum%p;
        if(rem == 0){
            return 0;
        }
        int n = nums.length;
        int ans = n, currSum=0;
        Map<Integer,Integer> modMap = new HashMap<>();
        modMap.put(0,-1);
        
        for(int i =0;i<n;i++){
            currSum = (currSum + nums[i])%p;
            int needed = (currSum - rem+p)%p;
            if(modMap.containsKey(needed)){
                ans = Math.min(ans, i- modMap.get(needed));
            }
            modMap.put(currSum, i);
        }
        return ans==n?-1:ans;
    }
}