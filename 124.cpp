class Solution {
public:
    
    long maxPathHelper(TreeNode* root, long & maxSeen)
    {
        if(!root) return std::numeric_limits<int>::min();
        
        long val = root->val;
        long maxFromLeft  = maxPathHelper(root->left, maxSeen);
        long maxFromRight = maxPathHelper(root->right, maxSeen);
        long bigger = std::max(maxFromLeft, maxFromRight);
        
        maxSeen = std::max(std::max(maxSeen, val + maxFromLeft + maxFromRight), bigger);
        return std::max(val, val + bigger);
    }

    int maxPathSum(TreeNode* root)
    {
        long maxSeen = std::numeric_limits<int>::min();
        long max = maxPathHelper(root, maxSeen);
        return std::max(max, maxSeen);
    }
};
