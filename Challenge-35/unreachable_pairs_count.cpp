class Solution {

private:
    void dfs(vector<int>adj[], int node, vector<int>&vis, long long &cnt){
        vis[node] = 1;
        cnt++;
        for(auto adjNode: adj[node]){
            if (!vis[adjNode]) dfs (adj,adjNode,vis,cnt);
        }
    }


public:
    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<int>vis(n,0);
        vector<int>adj[n];
        for (auto edge: edges){
            int u = edge[0], v= edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long ans =  ((long long) n * (n-1)) / 2;

        for (int i=0; i<n; i++){
            if(!vis[i]){
                long long cnt = 0;
                dfs (adj,i,vis,cnt);
                ans -= (cnt* (cnt-1))/2;
            }
        }

        return ans;
        
    }
};