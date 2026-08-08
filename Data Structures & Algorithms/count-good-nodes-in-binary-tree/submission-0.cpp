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
    void DFS(TreeNode* root, vector<int> path, int m)
    {
        if(root == nullptr)
            return;
        if(m <= root->val)
            cnt+=1;
        
        m = max(m, root->val);
        path.push_back(root->val);
        DFS(root->left, path, m);
        DFS(root->right, path, m);
    }
    int goodNodes(TreeNode* root) {
        vector<int> path;
        DFS(root,path , INT_MIN);
        return cnt;
    }
};

