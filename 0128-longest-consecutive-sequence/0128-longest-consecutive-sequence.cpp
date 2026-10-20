class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int it : st) {
            // Only start counting if it is the first element of a sequence
            if (st.find(it - 1) == st.end()) {
                int currVal = it;
                int currStreak = 1;

                // Keep checking for the next consecutive element in the set
                while (st.find(currVal + 1) != st.end()) {
                    currVal += 1;
                    currStreak += 1;
                }
                longest = max(longest, currStreak);
            }
        }
        return longest;
    }
};