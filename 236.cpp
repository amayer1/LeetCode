class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == NULL) return NULL;
        if (root->val == p->val || root->val == q->val) return root;
        TreeNode* rootLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* rootRight = lowestCommonAncestor(root->right, p, q);
        if(rootLeft && rootRight ) return root;
        if(rootLeft) return rootLeft;
        if(rootRight) return rootRight;
        return NULL;    
    }
};
