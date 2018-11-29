class Solution {
public:
    void backtrack(std::vector<int> & nums, std::vector<std::vector<int>> & res, std::vector<int> & curr, 
                  std::unordered_set<int> & usedIndex)
    {
        if(curr.size() == nums.size())
            res.push_back(curr);
        else
        {
            std::unordered_set<int> usedNum;
            for(int i = 0; i < nums.size(); i++)
            {
                if(usedNum.count(nums[i])) continue; 
                if(usedIndex.count(i)) continue;
                curr.push_back(nums[i]);
                usedIndex.insert(i);
                usedNum.insert(nums[i]);
                backtrack(nums, res, curr, usedIndex);
                curr.pop_back();
                usedIndex.erase(i);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        //std::sort(nums.begin(), nums.end());
        std::unordered_set<int> usedIndex;
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        backtrack(nums, res, curr, usedIndex);
        return res;
    }
};
