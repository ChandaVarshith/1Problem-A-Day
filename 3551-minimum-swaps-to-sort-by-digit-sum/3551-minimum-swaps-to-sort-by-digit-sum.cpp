class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int swaps = 0;

        vector<pair<int, int>> A;
        for (int i = 0; i < n; i++) {
            int t = nums[i];
            int sum = 0;

            while (t > 0) {
                sum += t % 10;
                t /= 10;
            }

            A.push_back({sum, nums[i]});
        }

        vector<pair<pair<int, int>, int>> C;
        for (int i = 0; i < n; i++) {
            C.push_back({A[i], i});
        }

        sort(C.begin(), C.end(), [&](auto a, auto b){
            if (a.first.first == b.first.first) {
                return a.first.second < b.first.second;
            }
            return a.first.first < b.first.first;
        });

        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] || C[i].second == i) continue;

            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = C[j].second;
                cycleSize += 1;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};









// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         int n = nums.size();
//         vector<pair<int,int>>sum;
//         for(int i = 0; i < n; i++ ){
//             int t = nums[i];
//             int sum = 0;
//             while(t>0){
//                 sum += t%10;
//                 t = t/10;
//             }
//             sum.push_back({sum,nums[i]});
//         }

//     }
// };