class Solution {
public:
    bool isValid(string s){
        int balance = 0;
        for(char a:s){
            if(a=='(')balance++;
            else balance--;
            if(balance<0) return false;
        }
        return balance==0;
    }
    void solve(int n,vector<string>&res,string para){
        if(para.size()==2*n){
            if(isValid(para)){
                res.push_back(para);
            }
            return ;
        }
        solve(n,res,para+'(');
        solve(n,res,para+')');
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        solve(n,res,"");
        return res;
    }
};