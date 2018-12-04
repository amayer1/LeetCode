class Solution {
public:
    int tiltHelper(TreeNode* root, int & tilt)
    {
        if(!root) return 0;
        int leftPath = tiltHelper(root->left, tilt);
        int rightPath = tiltHelper(root->right, tilt);
        tilt += abs(leftPath - rightPath);
        return leftPath + rightPath + root->val;
    }
    int findTilt(TreeNode* root) 
    {
        int tilt = 0;
        tiltHelper(root, tilt);
        return tilt;
    }
};
