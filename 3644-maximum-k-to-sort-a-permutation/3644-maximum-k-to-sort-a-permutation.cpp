class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                if(res ==INT_MIN) res = nums[i];
                else{
                    res &= nums[i];
                }
            }
        }
        return res==INT_MIN?0:res;
    }
};