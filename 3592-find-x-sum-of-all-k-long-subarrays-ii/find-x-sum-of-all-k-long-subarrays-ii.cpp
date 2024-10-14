class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        set<pair<int,int>, greater<pair<int,int>>> topx;
        set<pair<int,int>, greater<pair<int,int>>> rem;
        unordered_map<int,int> freqCount;
        vector<long long> output;
        long long sum = 0;
        for (int i = 0 ; i < k ; i++) {
            int prevFreq = freqCount[nums[i]];
            freqCount[nums[i]]++;
            if (topx.size() < x) {
                if (topx.find({prevFreq,nums[i]}) != topx.end()) {
                    topx.erase({prevFreq, nums[i]});
                }
                topx.insert({prevFreq+1, nums[i]});
            } else {
                if (topx.find({prevFreq,nums[i]}) != topx.end()) {
                    topx.erase({prevFreq, nums[i]});
                    topx.insert({prevFreq+1, nums[i]});
                } else {
                    if (rem.find({prevFreq,nums[i]}) != rem.end()) {
                        rem.erase({prevFreq, nums[i]});
                    }
                    rem.insert({prevFreq+1, nums[i]});
                    pair<int,int> lasttopX = *topx.rbegin();
                    pair<int,int> firstRem = *rem.begin();
                    if (lasttopX.first < firstRem.first || (lasttopX.first == firstRem.first && lasttopX.second < firstRem.second)) {
                        topx.erase(lasttopX);
                        rem.erase(firstRem);
                        topx.insert(firstRem);
                        rem.insert(lasttopX);
                    } 
                }
            }
        }
        for (auto ele: topx) {
            int freq = ele.first;
            int num = ele.second;
            sum += ((long long)freq*num);
        }
        output.push_back(sum);
        int start=0,end=k;
        while (end < nums.size()) {
            int prevFreq = freqCount[nums[end]];
            freqCount[nums[end]]++;
            if (topx.find({prevFreq,nums[end]}) != topx.end()) {
                topx.erase({prevFreq, nums[end]});
                topx.insert({prevFreq+1, nums[end]});
                sum += nums[end];
            } else {
                if (rem.find({prevFreq,nums[end]}) != rem.end()) {
                    rem.erase({prevFreq, nums[end]});
                }
                rem.insert({prevFreq+1, nums[end]});
                pair<int,int> lasttopX = *topx.rbegin();
                pair<int,int> firstRem = *rem.begin();
                if (topx.size() < x) {
                    rem.erase(firstRem);
                    topx.insert(firstRem);
                    sum += ((long long)firstRem.first * firstRem.second);
                } else if ((lasttopX.first < firstRem.first) || (lasttopX.first == firstRem.first && lasttopX.second < firstRem.second)) {
                    topx.erase(lasttopX);
                    rem.erase(firstRem);
                    topx.insert(firstRem);
                    rem.insert(lasttopX);
                    sum -= ((long long)lasttopX.first*lasttopX.second);
                    sum += ((long long)firstRem.first * firstRem.second);
                }
            }
            prevFreq = freqCount[nums[start]];
            freqCount[nums[start]]--;
            if (topx.find({prevFreq,nums[start]}) != topx.end()) {
                sum -= nums[start];
                topx.erase({prevFreq,nums[start]});
                topx.insert({prevFreq-1, nums[start]});
                pair<int,int> lasttopX = *topx.rbegin();
                pair<int,int> firstRem = *rem.begin();
                if (lasttopX.first < firstRem.first || (lasttopX.first == firstRem.first && lasttopX.second < firstRem.second)) {
                    topx.erase(lasttopX);
                    rem.erase(firstRem);
                    topx.insert(firstRem);
                    rem.insert(lasttopX);
                    sum -= ((long long)lasttopX.first*lasttopX.second);
                    sum += ((long long)firstRem.first * firstRem.second);
                }
            } else {
                if (rem.find({prevFreq,nums[start]}) != rem.end()) {
                    rem.erase({prevFreq, nums[start]});
                }
                rem.insert({prevFreq-1, nums[start]});
            }
            output.push_back(sum);
            end++;
            start++;
        }
        return output;
    }
};