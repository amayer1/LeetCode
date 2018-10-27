class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        std::unordered_map<char,char> patternMap;
        //std::unordered_set<char> alreadyMapped;
        std::bitset<26> alreadyMapped;
        std::vector<string> matchingStrings;
        
        for(auto str : words)
        {
            if(str.size() != pattern.size())
                continue;
            
            matchingStrings.push_back(str);
            for(int i = 0; i < str.size(); i++)
            {
               if(alreadyMapped[str[i] - 97])
               {
                   if(patternMap[pattern[i]] != str[i])
                   {
                       matchingStrings.pop_back();
                       break;
                   }
               }
               else
               {
                   if(patternMap.count(pattern[i]))
                   {
                       matchingStrings.pop_back();
                       break;
                   }
                   else
                   {
                       alreadyMapped.set(str[i] - 97);
                       patternMap[pattern[i]] = str[i];
                   }
               }
            }
        
            alreadyMapped.reset();
            patternMap.clear();
        }
        
        return matchingStrings;
    }
};
