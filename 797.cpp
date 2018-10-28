/*
 * Find all paths from source to a vertex
 */

class Solution {
public:
    
    void findAllEdgesIncidentOn(vector<vector<int>>& graph, int vertex, vector<int>& incidentOn)
    {
        for(int i = 0; i < vertex; i++)
        {
            for(int j = 0; j < graph[i].size(); j++)
            {
                if(graph[i][j] == vertex)
                {
                    incidentOn.push_back(i);
                    break;
                }
            }
        }
    }
    
    void addVectorToPath(std::unordered_map<int, std::vector<vector<int>>>& memo, int vertex, int v)
    {
        int initSize = memo[vertex].size();
        for(auto path : memo[v])
            memo[vertex].push_back(path);
        for(int i = initSize; i < memo[vertex].size(); i++)
            memo[vertex][i].push_back(vertex);
    }
    
    vector<vector<int>> findAllPathsToVector(vector<vector<int>>& graph, int vertex,               std::unordered_map<int, std::vector<vector<int>>>& memo)
    {
        
        if(memo.count(vertex))
        {
            return memo[vertex];
        }
        
        vector<int> incidentOn;
        findAllEdgesIncidentOn(graph, vertex, incidentOn);
        
        for(auto v : incidentOn)
        {
            if(memo.count(v))
                addVectorToPath(memo, vertex, v);
             else
             {
                 memo[v] = findAllPathsToVector(graph, v, memo);
                 addVectorToPath(memo, vertex, v);
             }
        }
        return memo[vertex];
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        std::vector<vector<int>> allPaths;
        std::vector<int> singlePath;
        std::unordered_map<int, std::vector<vector<int>>> memo;
        
        std::vector<int> pathToZero = {0};
        memo[0].push_back(pathToZero);
        
        return findAllPathsToVector(graph, graph.size()-1, memo);
    }
};
