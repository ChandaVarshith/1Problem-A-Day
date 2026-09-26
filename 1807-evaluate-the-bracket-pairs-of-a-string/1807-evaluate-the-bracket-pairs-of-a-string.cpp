class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        int m = knowledge.size();
        string word = "";
        unordered_map<string,string>mpp;
        for(int i=0;i<m;i++){
            mpp[knowledge[i][0]]=knowledge[i][1];
        }
        for(int i=0;i<n;i++){
            
            if(s[i]=='('){
                string temp = "";
                i++;
                //int start = i;
                while(i<n && s[i]!=')'){
                    temp+=s[i];
                    i++;
                }
                if(mpp.find(temp)!=mpp.end()){
                    word += mpp[temp];
                }
                else{
                    word += "?";
                }
            }
            else{
                word += s[i];
            }
        }
        return word;
    }
};