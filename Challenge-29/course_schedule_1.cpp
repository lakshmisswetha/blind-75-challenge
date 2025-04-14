class Solution {
public:

    bool dfs(int node, vector<vector<int>> &graph, vector<int> &visited){
        if (visited[node]==1) return true;
        if (visited[node]==2) return false;

        visited[node]=1;

        for(int neighbor : graph[node]){
            if (dfs(neighbor,graph,visited)) return true;
        }

        visited[node] = 2;
        return false;
    }



    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites){
            graph[p[1]].push_back(p[0]);
        } 
        vector<int>visited(numCourses, 0);
        for (int i=0; i<numCourses; i++){
             if(dfs(i,graph,visited)) return false;

        }

        return true;
        
    }
};