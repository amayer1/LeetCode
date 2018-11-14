/*
 * Level order traversal - BFS
 * Can be done with DFS also
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        std::vector<int> res;
        if(!root) return res;
        std::queue<TreeNode*> frontier;
        frontier.push(root);
        while(!frontier.empty())
        {
            res.push_back(frontier.front()->val);
            int frontierSize = frontier.size();
            for(int i = 0; i < frontierSize; i++)
            {
                TreeNode* curr = frontier.front();
                frontier.pop();
                if(curr->right) frontier.push(curr->right);
                if(curr->left)  frontier.push(curr->left);
            }
        }
        return res;
    }
};
