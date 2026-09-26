class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int rowDiff = abs(source[0]-target[0]);
        int colDiff = abs(source[1]-target[1]);
        if(rowDiff==0 && colDiff == 0)return 0;
        if(rowDiff==0) return 1;
        if(colDiff==0) return 1;
        if(rowDiff==colDiff) return 1;
        return 2;
    }
};