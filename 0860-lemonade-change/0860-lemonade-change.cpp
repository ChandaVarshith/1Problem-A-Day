class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        vector<int>five;
        vector<int>ten;
        for(int i=0;i<n;i++){
            if(bills[i]==5) five.push_back(bills[i]);
            else if(bills[i]==10){
                if(five.size()>0) five.pop_back();
                else{
                    return false;
                }
                ten.push_back(bills[i]);
            }
            else{
                //15 change should be given
                if(ten.size()>0){ 
                    ten.pop_back();
                    if(five.size()>0){
                        five.pop_back();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(five.size()>=3){
                        int count = 3;
                        while(count!=0){
                            five.pop_back();
                            count--;
                        }
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};