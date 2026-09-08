class Solution {
public:
    int countCommas(int n) {
        return n>999?n-1000+1:0;
    }
};