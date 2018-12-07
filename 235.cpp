class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {   
        if(root->val == p->val || root->val == q->val) return root;
        int higher, lower = std::min(p->val, q->val);
        (lower == p->val) ? higher = q->val : higher = p->val;
        if(root->val > lower && root->val < higher) return root;
        if(root->val < lower) return lowestCommonAncestor(root->right, p , q);
        return lowestCommonAncestor(root->left, p, q);
    }
};

