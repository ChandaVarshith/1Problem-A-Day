class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int level = 0;
        //if stack is empty add to temp stack, dont add to the ans string (for ")" pop for "(" push )
        //if stack is not empty add to the temp , add to the ans string
        for(int i=0;i<s.length();i++){
            if(s[i]== '('){
                if(level>0){
                    ans += s[i];
                }
                level++;
            }
            if(s[i] == ')'){
                //first remove the level then check the level is 0 or not acc to that add or not add into new ans
                level--;
                if(level >0){
                    ans += s[i]; 
                }
            }
        }
        return ans;
    }
};