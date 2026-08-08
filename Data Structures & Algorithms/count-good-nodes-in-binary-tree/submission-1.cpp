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
    int cnt = 0;
    void DFS(TreeNode* root, int m)
    {
        if(root == nullptr)
            return;
        if(m <= root->val)
            cnt+=1;
        
        m = max(m, root->val);
        DFS(root->left,m);
        DFS(root->right,m);
    }
    int goodNodes(TreeNode* root) {
        DFS(root,INT_MIN);
        return cnt;
    }
};

