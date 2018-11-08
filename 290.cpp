class Solution {
public:
    bool wordPattern(string pattern, string str) 
    {
        int pSize = pattern.size();
        std::istringstream iss(str);
        
        std::unordered_map<char, std::string> dict;
        std::unordered_set<std::string> strSeen;
        int index = 0;
        std::string w;
        while(index < pSize && iss >> w)
        {
            if((dict.count(pattern[index]) && dict[pattern[index]] != w) ||
               !dict.count(pattern[index])  && strSeen.count(w))
                return false;
            
            dict[pattern[index]] = w;
            strSeen.insert(w);          
            index++;
        }
        if(iss.eof() && index == pSize)  return true;
        
        return false;
    }
};
