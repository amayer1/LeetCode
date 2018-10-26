class Solution {
public:
    int numJewelsInStones(string J, string S) 
    {
        std::unordered_set<char> jewelSet;
        for(int i = 0; i < J.size(); i++)
        {
            jewelSet.insert(J[i]);
        }
        int num = 0;
        for(int i = 0; i < S.size(); i++)
        {
            if(jewelSet.count(S[i]))
                num++;
        }
        return num;
    }
};
