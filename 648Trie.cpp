/*
 * First implemented with a dictionary. Now I'm using a trie
 */
class Solution {
public:
    
    struct TrieNode
    {
        std::unordered_map<char, TrieNode*> map;
        bool isRoot;
        TrieNode(bool x) : isRoot(x) {}
    };
    void trieInsert(string & str, TrieNode & root)
    {
        TrieNode* trav = &root;
        for(char c : str)
        {
            if(!trav->map.count(c))
                trav->map[c] = new TrieNode(false);       
            trav = trav->map[c];
        }
        trav->isRoot = true;
    }
    string checkPrefix(string & str, TrieNode & root)
    {
        string newStr = "";
        TrieNode* trav = &root;
        for(char c : str)
        {
            newStr += c;
            if(trav->map.count(c))
                trav = trav->map[c];
            else
                return str;
            if(trav->isRoot)
                return newStr;
        }
        return newStr;
    }
    string replaceWords(vector<string>& dict, string sentence) 
    {
        TrieNode root(false);
        for(string & str : dict)
            trieInsert(str, root);
        std::istringstream strstr(sentence);
        string str, res = "";
        while(strstr >> str)
            res += checkPrefix(str, root) + " ";
        return res.substr(0, res.size()-1);
    }
};
