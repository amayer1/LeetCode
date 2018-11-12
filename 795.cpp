/*
 * Advice: I solved this on my own, but there is a really simple 10 line
 * solution that I took notes on. A lot to learn!!!
 */
class Solution {
public:
    
    struct Sub
    {
        int subArrLen;
        int L;
        std::vector<int> subtract;
        Sub(int L) : subArrLen(0), L(L) {}
    };
    
    int numSubArrays(Sub & sub)
    {
        if(sub.subArrLen == 0) return 0;
        
        int minus = 0;
        for(int i : sub.subtract)
            minus += (i * (i+1))/2;
        return ((sub.subArrLen*(sub.subArrLen+1))/2) - minus;
    }
    int numSubarrayBoundedMax(vector<int>& A, int L, int R)
    {
        int res = 0;
        int arrSize = A.size();
        bool consLess = false;
        Sub sub(L);
        for(int i = 0; i < arrSize; i++)
        {
            if(A[i] > R)
            {
                res += numSubArrays(sub);
                sub.subtract.clear();
                sub.subArrLen = 0;
                consLess = false;
                continue;
            }  
            if(A[i] < L)
            {
                if(!consLess)
                {
                    sub.subtract.push_back(1);
                    consLess = true;
                }
                else
                    sub.subtract.back()++;
            }
            else 
                consLess = false; 
            sub.subArrLen++;
        }
        
        return res + numSubArrays(sub);
    }
};

