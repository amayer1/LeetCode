/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSame(TreeNode* s, TreeNode* t)
    {
        if(s == NULL && t == NULL)
            return true;
        else if(s == NULL || t == NULL)
            return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right) && s->val == t->val;
    }
    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        if(s == NULL) return false;
        if(s->val  == t->val && isSame(s,t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
