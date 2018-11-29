class Solution {
public:
    void backtrack(std::vector<int> & candidates, std::vector<std::vector<int>> & res, int target, std::vector<int> & curr, 
                   int  currSum, int start)
    {
        if(currSum == target)
            res.push_back(curr);
        else if(currSum < target)
        {
            for(int i = start; i < candidates.size(); i++)
            {
                if(i != start && candidates[i] == candidates[i-1]) continue;
                currSum += candidates[i];
                if(currSum > target) break;
                curr.push_back(candidates[i]);
                backtrack(candidates, res, target, curr, currSum, i + 1);
                currSum -= candidates[i];
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> res;
        std::vector<int> curr; 
        backtrack(candidates, res, target, curr, 0, 0);
        return res;
    }
};
