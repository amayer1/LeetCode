class Solution {
public:
    int totalFruit(vector<int>& tree) 
    {
        int leftAnchor = 0;
        int currNum, otherNum = tree[0], currNumLast, res = 0;
        
        int i;
        for(i = 1; i < tree.size() && otherNum == tree[i]; i++){};
        if(i == tree.size()) return i;
        currNum = tree[i];
        currNumLast = i;
        for(i = i + 1; i < tree.size(); i++)
        {
            if(tree[i] != currNum && tree[i] != otherNum)
            {
                res = std::max(res, i - leftAnchor);
                leftAnchor = currNumLast;
                otherNum = currNum;
                currNum = tree[i];
                currNumLast = i;
            }
            else if(tree[i] != currNum)
            {
                currNumLast = i;
                int temp = currNum;
                currNum = otherNum;
                otherNum = temp;
            }
        }
        return std::max(res, i-leftAnchor);      
    }
};
