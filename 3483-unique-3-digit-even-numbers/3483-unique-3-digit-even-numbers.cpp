class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_map<int,int>mpp;
        for(int digit : digits){
            mpp[digit]++;
        }
        int res = 0;
        for(int i=100;i<1000;i+=2){
            int curr = i;
            unordered_map<int,int>temp = mpp;
            while(curr>0){
                int last = curr % 10;
                if(temp.find(last)!=temp.end()){
                    curr = curr/10;
                    temp[last]--;
                    if(temp[last]==0) temp.erase(last);
                }
                else{
                    break;
                }
            }
            if(curr<=0){
                res+=1;
            }
        }
        return res;
    }
};