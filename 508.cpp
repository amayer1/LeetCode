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
    int helper(TreeNode* root, std::unordered_map<int, int> & freq)
    {
        if(!root) return 0;
        int currSum  = root->val;
        if(root->left)
            currSum += helper(root->left, freq);
        if(root->right)
             currSum += helper(root->right, freq);
        freq[currSum]++;
        return currSum;
    
    }
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        std::unordered_map<int, int> freq;
        std::vector<int> res;
        
        helper(root, freq);
        
        int maxFreq = -1;
        for(auto & each : freq)
        {
            if(each.second > maxFreq)
                maxFreq = each.second;
        }

        for(auto & each : freq)
        {
            if(each.second == maxFreq)
                res.push_back(each.first);
        }
        return res;
    }
};
