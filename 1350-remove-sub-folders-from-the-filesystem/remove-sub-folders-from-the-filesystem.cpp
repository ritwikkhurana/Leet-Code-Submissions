class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> hashSet;
        vector<string> output;
        for (string path: folder) {
            hashSet.insert(path);
        }

        for (string path: folder) {
            bool isSubpath = false;
            for (int i = 0 ; i < path.size() ; i++) {
                if (path[i] == '/') {
                    if (hashSet.find(path.substr(0,i)) != hashSet.end() && i != path.size()-1) {
                        isSubpath = true;
                        break;
                    }
                }
            }
            if (!isSubpath) {
                output.push_back(path);
            }
        }
        return output;
    }
};