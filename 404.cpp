class Solution {
public:
    bool isLeaf(TreeNode* node)
    {
        if(node->right || node->left)
            return false;
        return true;
    }
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(!root) return 0;

        if(root->left && isLeaf(root->left))
            return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
