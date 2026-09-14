class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n1 = img1.size(), m1 = img1[0].size(), n2 = img2.size(), m2 = img2[0].size();
        
        vector<pair<int, int>> ind1;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m1; j++) {
                if (img1[i][j] == 1) {
                    ind1.push_back({i, j});
                }
            }
        }

        vector<pair<int, int>> ind2;
        for (int i = 0; i < n2; i++) {
            for (int j = 0; j < m2; j++) {
                if (img2[i][j] == 1) {
                    ind2.push_back({i, j});
                }
            }
        }

        int ans = 0;
        map<pair<int, int>, int> mp;
        for (auto &it1 : ind1) {
            for (auto &it2 : ind2) {
                auto dr = it2.first - it1.first;
                auto dc = it2.second - it1.second;

                mp[{dr, dc}]++;
                ans = max(ans, mp[{dr, dc}]);
            }
        }

        return ans;
    }
};