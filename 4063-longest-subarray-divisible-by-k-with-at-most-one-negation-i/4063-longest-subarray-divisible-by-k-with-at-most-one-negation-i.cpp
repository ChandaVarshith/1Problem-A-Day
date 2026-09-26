class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pref(n,0);
        int ans =0;
        pref[0] = nums[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            set<int>st;
            for(int j=i;j<n;j++){
                int val = (2LL*nums[j])%k;
                if(val<0)val+=k;
                st.insert(val);

                long long sum;
                if(i==0){
                    sum = pref[j];
                }
                else{
                    sum = pref[j]-pref[i-1];
                }
                int rem = sum%k;
                if(rem<0)rem+=k;
                if(rem == 0){
                    ans = max(ans,j-i+1);
                }
                else if(st.count(rem)){
                    ans = max(ans,j-i+1);
                }
            }
        
        }
        return ans;        
    }
};