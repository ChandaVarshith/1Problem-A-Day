class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefMax(n,0);
        vector<int>prefMin(n,0);
        prefMax[0] = nums[0];
        int maxi = prefMax[0];
        for(int i=1;i<n;i++){
            maxi = max(maxi,nums[i]);
            prefMax[i] = maxi;
        }
        prefMin[n-1] =nums[n-1];
        int mini = prefMin[n-1]; 
        for(int i=n-2;i>=0;i--){
            mini = min(mini,nums[i]);
            prefMin[i] = mini;
        }
        
        for(int i=0;i<n;i++){
            if(prefMax[i]-prefMin[i]<=k){
                return i;
            }
            
        }

        return -1;
    }
};