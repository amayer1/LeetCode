class Solution {
public:
    TreeNode* constructMaxBinaryTree(vector<int>& nums, vector<int>::iterator start, vector<int>::iterator end)
    {
       TreeNode* node = new TreeNode(0); 
       if(start >= end)
       {
           node->val = *start;
           return node;
       }
       auto largestIter = std::max_element(start, end);
       node->val = *largestIter;
       node->left  = constructMaxBinaryTree(nums, start, largestIter);
       node->right = constructMaxBinaryTree(nums, largestIter + 1, end);
       
       return node;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return constructMaxBinaryTree(nums, nums.begin(), nums.end());
    }
};
