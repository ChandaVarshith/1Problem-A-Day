class Solution {
public:

    vector<pair<int,int>> pairr(string a,string b){
        stringstream ss1(a);
        stringstream ss2(b);
        vector<pair<int,int>>res;
        int month,day;
        char dash;
        if(ss1>>month>>dash>>day){
            res.push_back({month,day});
        }
        if(ss2>>month>>dash>>day){
            res.push_back({month,day});
        }
        return res;        
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>maxDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int tDays_Alice = 0;
        int tDays_Bob = 0;
        //total cal for alice
        vector<pair<int,int>>alice = pairr(arriveAlice,leaveAlice);
        vector<pair<int,int>>bob = pairr(arriveBob,leaveBob);;
        // cout<<alice[0].first<<" "<<alice[0].second;
        pair<int,int> a[2];
        a[0] = max(alice[0],bob[0]);
        a[1] = min(alice[1],bob[1]);
        // cout<<a[0].first<<" "<<a[0].second;
        int startDay = 0;
        int endDay = 0;
        // cout<<a[0].first<<" ";
        for(int i=0;i<a[0].first -1;i++){
            startDay +=  maxDays[i];
        }
        startDay += a[0].second;
        for(int i=0;i<a[1].first-1;i++){
            endDay += maxDays[i];
        }
        endDay += a[1].second;
        if(endDay<startDay) return 0;
        return endDay-startDay+1;

    }
};