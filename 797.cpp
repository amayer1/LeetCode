/*
 * Find all paths from source to a vertex
 *
 * Note: This isn't my solution. After I correctly submitted a solution, I
 * decided to look at a better one by someone else to see how I can improve.
 * This person used DFS. I thought about using DFS, but I wasn't sure how to
 * work it out with the stack. 
 *
 * Lesson: See how he handled the stack frame! Inline Comments
 */

class Solution {
public:
    /*
     * I was nervous about the 'path' variable. Each stack frame needed its own
     * path. I was nervous about passing 'path' by value because copying is
     * expensive. At the same time, if I passed it by reference it would mess up
     * other in progress.
     *
     * This guy just passed in 'path' by value!
     */
    void DFS(vector<vector<int>>& graph, std::vector<vector<int>>& allPaths, std::vector<int> path, int curr)
    {
        //Add current vertex we're visiting to the path
        path.push_back(curr);
        //If we've reached destination, add current path to allPaths
        if(curr == graph.size()-1)
        {
            allPaths.push_back(path);
        }
        else //If we haven't reached destination
        {
            //Choose a vertex coming connected to it and pursue it
            for(auto v : graph[curr])
            {
                DFS(graph, allPaths, path, v);
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        std::vector<vector<int>> allPaths;
        std::vector<int> path;
        DFS(graph, allPaths, path, 0);
        return allPaths;
    }
};
