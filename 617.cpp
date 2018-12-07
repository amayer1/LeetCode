class Solution {
public:
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        if(t1 == NULL && t2 == NULL) return NULL;
        if(t2 == NULL) return t1;
        if(t1 == NULL) return t2;
        
        TreeNode* merged = new TreeNode(t1->val + t2->val);
        merged->left  = mergeTrees(t1->left, t2->left);
        merged->right = mergeTrees(t1->right, t2->right);
        return merged;    
    }
};

