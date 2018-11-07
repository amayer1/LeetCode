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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        std::vector<vector<int>> returnArr;
        if(!root)   return returnArr;
        
        std::vector<int> row;
        std::queue<TreeNode*> myQueue;
        myQueue.push(root);
        std::stack<std::vector<int>> myStack;
        
        while(myQueue.size())
        {
            int size = myQueue.size();
            for(int i = 0; i < size; i++)
            {
                if(myQueue.front()->left) myQueue.push(myQueue.front()->left);
                if(myQueue.front()->right) myQueue.push(myQueue.front()->right);
                row.push_back(myQueue.front()->val);
                myQueue.pop();     
            }
            myStack.push(row);
            row.clear();
        }
        std::cout << "HERE";
        while(!myStack.empty())
        {
            returnArr.push_back(myStack.top()); 
            myStack.pop();
        }   
        
        return returnArr;
    }
};
