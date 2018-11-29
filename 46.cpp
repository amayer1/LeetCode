class Solution {
public:
    void backtrack(std::vector<int> & nums, std::vector<std::vector<int>> & res, std::vector<int> & curr, 
                   std::unordered_set<int> & used)
    {
        if(curr.size() == nums.size())
            res.push_back(curr);
        else
        {
            for(int i = 0; i < nums.size(); i++)
            {
                if(used.count(i)) continue;
                curr.push_back(nums[i]);
                used.insert(i);
                backtrack(nums, res, curr, used);
                curr.pop_back();
                used.erase(i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        std::unordered_set<int> used;
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        backtrack(nums, res, curr, used);
        return res;
    }
};
