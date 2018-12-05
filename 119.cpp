class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        std::vector<int> res(rowIndex + 1, 1);
        for(int i = 2; i < rowIndex + 1; i++)
        {
            int prev = 1;
            for(int j = 1; j < i; j++)
            {
                int temp = res[j];
                res[j] = temp + prev;
                prev = temp;
            }
        }
        return res;
    }
};
