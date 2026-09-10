/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) return {0, 0};
        
        auto l = dfs(node -> left);
        auto r = dfs(node -> right);

        int sum = l.first + r.first + node -> val;
        int sz = l.second + r.second + 1;

        int avg = sum / sz;

        if (avg == node-> val) ans++;

        return {sum, sz};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};