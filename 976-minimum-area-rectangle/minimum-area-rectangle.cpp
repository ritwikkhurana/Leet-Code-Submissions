class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int,vector<int>> xPoints;
        unordered_map<int,vector<int>> yPoints;
        set<pair<int,int>> allPoints;
        for (auto i: points) {
            xPoints[i[0]].push_back(i[1]);
            yPoints[i[1]].push_back(i[0]);
            allPoints.insert({i[0], i[1]});
        }

        int minArea = INT_MAX;

        for (auto point : points) {
            int x = point[0];
            int y = point[1];

            for (int yPoint : xPoints[x]) {
                for (int xPoint : yPoints[y]) {
                    if (x!=xPoint && y!=yPoint && allPoints.find({xPoint, yPoint}) != allPoints.end()) {
                        minArea = min(minArea, (abs(x-xPoint) * abs(y-yPoint)));
                    }
                }
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};