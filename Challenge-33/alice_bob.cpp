class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {

        vector<vector<vector<int>>> qs(heights.size());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<int> res(queries.size(),-1);

        for (int i=0; i<queries.size(); i++){
            int a = queries[i][0], b = queries[i][1];
            int mini = min (a,b), maxi = max(a,b);

            if(mini==maxi || heights[maxi] > heights[mini]) res[i]=maxi; 
            else {
                qs[maxi].push_back({ max(heights[mini], heights[maxi]), i });

            }
             
        }

        for (int i=0; i<heights.size(); i++){
            while(!pq.empty() && pq.top()[0] < heights[i]){
                res[pq.top()[1]] = i;
                pq.pop();
            }



            for(auto it : qs[i]){
                pq.push(it);
            }
        }

        return res;

        
    }
};