/*
 * Honestly, not a great solution. Works but slow. Took notes on this one
 */
class Solution {
public:
    std::unordered_map<int,int> pathHelper(TreeNode* root, int sum, int & res)
    {
        std::unordered_map<int,int> dict;
        if(!root) return dict;
             
        std::unordered_map<int,int> pathsFromLeft  = pathHelper(root->left, sum, res);
        std::unordered_map<int,int> pathsFromRight = pathHelper(root->right, sum, res);
        
        if(root->val == sum) 
            res++;
        if(pathsFromLeft.count(root->val))
            res += pathsFromLeft[root->val];
        if(pathsFromRight.count(root->val))
            res += pathsFromRight[root->val];
        
        dict[sum - root->val]++;
        for(auto & each : pathsFromLeft)
            dict[each.first - root->val] += each.second;
        for(auto & each : pathsFromRight)
            dict[each.first - root->val] += each.second;
        
        return dict; 
    }
    int pathSum(TreeNode* root, int sum)
    {
        int res = 0;
        std::unordered_map<int, int> dummy = pathHelper(root, sum, res);
        return res;
    }
};
