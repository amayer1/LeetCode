class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) 
    {
        std::istringstream str1s (A);
        std::istringstream str2s (B);
        std::unordered_map<std::string, int> map;
        std::vector<std::string> res;
        std::string str;
        while(str1s >> str)
            map[str]++;
        while(str2s >> str)
            map[str]++;
        for(auto & s : map)
        {
            if (s.second == 1)  
                res.push_back(s.first);
        }
        
        return res;
            
    }
};
