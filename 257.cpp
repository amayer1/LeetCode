/*
 * Lessons: 1) the insert() function with vectors is really important! 2) The
 * std::to_string(..) function is also important in converting # to a
 * std::string. 
 *
 * Finally, this just shows the value of thinking recursively: At a root, get
 * all to the left, get all to the right. Same problem but on a smaller input.
 * Took some brief notes on this
 */

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        std::vector<std::string> res;
        if(!root) return res;  
        if(!root->left && !root->right)
        {
            res.push_back(std::to_string(root->val));
            return res;
        }
        
        std::vector<std::string> pathsToLeft = binaryTreePaths(root->left);
        res.insert(res.begin(), pathsToLeft.begin(), pathsToLeft.end()); //Notice the use of insert!
       
        std::vector<std::string> pathToRight = binaryTreePaths(root->right);
        res.insert(res.end(), pathToRight.begin(), pathToRight.end());
        
        std::string str = std::to_string(root->val) + "->";
        for(auto & each : res)
            each = str + each;
        return res;
    }
};
