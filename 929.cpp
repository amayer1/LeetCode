class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        int res;
        std::unordered_set<std::string> emailSet;
        for(std::string & emailAdd : emails)
        {
            int atPoint = emailAdd.find_first_of("@");
            int domainLen = emailAdd.size() - atPoint - 1;
            std::string str = emailAdd.substr(atPoint+1, domainLen);
            for(int i = 0; i < atPoint && emailAdd[i] != '+'; i++)
            {
                if(emailAdd[i] == '.') continue;
                str.push_back(emailAdd[i]);
            }
            emailSet.insert(str);
        }
        return emailSet.size();
    }
};
