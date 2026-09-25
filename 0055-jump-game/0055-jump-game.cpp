class Solution {
public:

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxiInd = 0;
        for(int i=0;i<n-1;i++){
            if(maxiInd<i) break;
            maxiInd = max(maxiInd,nums[i]+i);
        }
        return maxiInd>=n-1;
    }
};