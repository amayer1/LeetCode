/*
 * Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
 *
 * This is pretty easy. Some things to note though: 1) At first I was calculating the 'moving average', but that's unnecesary. It still works, but it's more effecient to just ca   calulate a moving sum and divide at the very end 2) I liked how I kept the edges of the window moving in the for loop. By initializing both to be edges of window and then
   incrementing both on each iteration.
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        if(nums.size() < k)
            return 0.;
        
        double maxSum = std::accumulate(nums.begin(), nums.begin() + k, 0);
        double movingSum = maxSum; 
        
        for(int i = k, j = 0; i < nums.size(); i++, j++)
        {
            
            movingSum -= nums[j];
            movingSum += nums[i];
            
            if(movingSum > maxSum)
                maxSum = movingSum;
        }
        
        return maxSum / k;
    }
};
