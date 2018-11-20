/*
 * BACKTRACKING - wrote about it in Notebook
 */
class Solution {
public:
    void subsetHelper(vector<int> & nums, std::vector<std::vector<int>> & res, int pos, std::vector<int> & curr)
    {
        if(pos == nums.size())
            res.push_back(curr);
        else
        {
            curr.push_back(nums[pos]);
            subsetHelper(nums, res, ++pos, curr);
            curr.pop_back();
            subsetHelper(nums, res, pos, curr);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        subsetHelper(nums, res, 0, curr);
        return res;
    }
};
