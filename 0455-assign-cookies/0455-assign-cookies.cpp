class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int count = 0;
        map<int,int>mpp;
        for (int num : s) {
            mpp[num]++; 
        }
        sort(g.begin(),g.end());
        for(int i=0;i<n;i++){
            for(auto& it:mpp){
                if(it.first>=g[i]){
                    count++;
                    it.second--;
                    if(it.second==0){
                        mpp.erase(it.first);
                    }
                    break;
                }
            }
        }
        return count;
    }
};