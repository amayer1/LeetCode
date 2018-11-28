class Solution {
public:
    void helper(std::vector<int> & candidates, int target, std::vector<std::vector<int>> & res, std::vector<int> & curr, 
                int currSum, int start)
    {
        if(currSum == target)
            res.push_back(curr);
        else if(currSum <= target)
        {
            int size = candidates.size();
            for(int i = start; i < size; i++)
            {
                curr.push_back(candidates[i]);
                currSum += candidates[i];
                helper(candidates, target, res, curr, currSum, i);
                curr.pop_back();
                currSum -= candidates[i];
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        helper(candidates, target, res, curr, 0, 0);
        return res;
    }
};
