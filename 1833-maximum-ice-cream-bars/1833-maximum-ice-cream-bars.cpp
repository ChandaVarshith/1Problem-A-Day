class Solution {
public:
    int maxIceCream(vector<int>& costs, long long coins) {
        int n =costs.size();
        long long total_bars=0;
        int maxi = *max_element(costs.begin(),costs.end());
        vector<long long>cntArr(maxi+1,0);

        for(int i=0;i<n;i++){
            cntArr[costs[i]]++;
        }
        for(int i=1;i<maxi+1;i++){
            cntArr[i] = cntArr[i-1]+cntArr[i];
        }
        vector<int>res(n,0);
        for(int i=n-1;i>=0;i--){
            res[cntArr[costs[i]]-1] = costs[i];
            cntArr[costs[i]]--;
        }
        // for(int i=0;i<n;i++){
        //     cout<<res[i]<<" ";
        // }
        for(int i=0;i<n;i++){
           coins -= res[i];
           if(coins>=0)
            total_bars++;
        }
        return total_bars;
    }
};