class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int  n = intervals.size();
        int count = 0;
        sort(intervals.begin(),intervals.end());

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<2;j++){
        //         cout<<intervals[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        int prevEnd = intervals[0][1]; 
        for(int i=1;i<n;i++){
            if(prevEnd > intervals[i][0]){
                cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
                count++;
                prevEnd = min(prevEnd,intervals[i][1]);
            }
            else{
                prevEnd = intervals[i][1];
            }
        }
        return count;
    }
};