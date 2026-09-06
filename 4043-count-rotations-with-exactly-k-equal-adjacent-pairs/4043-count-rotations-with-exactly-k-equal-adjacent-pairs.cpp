class Solution {
public:
    int countRotations(string s, int k) {
        int n  = s.size();
        int equalPair =0;
        for(int i=0;i<n;i++){
            if(s[i]==s[(i+1)%n]){
                equalPair++;
            }
        }
        int unequalPair = n-equalPair;
        if(k==equalPair) return  unequalPair;        
        if(k==equalPair-1) return  equalPair;        
        return 0;
    }
};