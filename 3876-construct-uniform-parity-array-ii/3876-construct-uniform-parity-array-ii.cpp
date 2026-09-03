class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int minEven = INT_MAX;
        int minOdd = INT_MAX;

        for (auto &p : nums1){
            if(p & 1){
                //odd
                minOdd = min(minOdd,p);
            }
            else{
                minEven = min(minEven,p);
            }
        }
        if(minEven==INT_MAX || minOdd == INT_MAX) return true;
        return minEven>minOdd;
    }
};