class Solution {
public:

    vector<int> dir = {0, 1, 0, -1, 0};

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j){
        visited[i][j] = true;
        int m = heights.size(), n = heights[0].size();
        for (int d=0; d<4; d++){
            int x = i + dir[d];
            int y = j + dir[d+1];

            if(x<0 || x>=m || y<0 || y>=n || visited[x][y] || heights[x][y] < heights[i][j]) continue;

            dfs(heights, visited, x, y);
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));
        vector<vector<int>>res;

        for (int i=0; i<m; i++){
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n-1);
        }

        for(int j=0; j<n; j++){
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m-1, j);
        }


        for (int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }

        return res;
        
    }
};