class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

   
        int t_count[128] = {0};
        int window[128] = {0};

        for (char c : t) t_count[c]++;

        int left = 0, right = 0;
        int min_len = INT_MAX, min_start = 0;
        int required = t.length(); 

        while (right < s.length()) {
            char c = s[right];
            if (t_count[c] > 0) {
                if (window[c] < t_count[c])
                    required--;
                window[c]++;
            }

        
            while (required == 0) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }

                char l = s[left];
                if (t_count[l] > 0) {
                    window[l]--;
                    if (window[l] < t_count[l])
                        required++;
                }
                left++;
            }

            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};
