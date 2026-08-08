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
    int preInd = 0;
    unordered_map<int,int> mp;
    TreeNode* build(vector<int>& preorder, int l, int r)
    {
        if(l > r)
            return nullptr;
        
        int rootVal = preorder[preInd];
        int rootInd = mp[rootVal];

        TreeNode* root = new TreeNode(rootVal);
        preInd++;

        root->left = build(preorder, l, rootInd-1);
        root->right = build(preorder, rootInd+1, r);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i< inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size()-1);
    }
};
