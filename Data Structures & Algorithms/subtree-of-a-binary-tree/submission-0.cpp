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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        
        if((p!= nullptr && q == nullptr) || (p==nullptr && q!= nullptr))
            return false;
        
        if(p->val != q->val)
            return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool ans = false;
    void traverse(TreeNode* r, TreeNode* s)
    {
        if( r == nullptr)
            return;
        
        if(r->val == s->val)
        {
            if(isSameTree(r, s))
            {
                ans = true;
                return;
            };
        }

        traverse(r->left, s);
        traverse(r->right, s);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr)
            return true;

        traverse(root, subRoot);
        return ans;
    }
};
