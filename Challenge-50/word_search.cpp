class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx == word.length()) return true;

      
        if (i < 0 || i >= board.size() || 
            j < 0 || j >= board[0].size() || 
            board[i][j] != word[idx]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#'; 

   
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        bool found = false;

        for (auto [dx, dy] : directions) {
            if (dfs(board, word, i + dx, j + dy, idx + 1)) {
                found = true;
                break;
            }
        }

        board[i][j] = temp; 
        return found;
    }
};
