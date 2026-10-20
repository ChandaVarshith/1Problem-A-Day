class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merged;
        int j = -1;
        for(int i=0;i<n;i++){
            if(merged.empty() || merged[j][1]<intervals[i][0]){
                merged.push_back(intervals[i]);
                j++;
            }
            else{
                merged[j][1] = max(merged[j][1],intervals[i][1]);
            }
        }
        return merged;
    }
};