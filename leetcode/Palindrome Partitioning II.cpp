class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<vector<int> > dp(len);
        for (int i = 0; i < len; i++) dp[i].resize(len, -1);
        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
            if (i < len - 1 && s[i] == s[i+1]) dp[i][i+1] = 1;
        }
        for (int l = 2; l < len; l++) {
            for (int i = 0; i < len; i++) {
                int j = i+l;
                if (j >= len) continue;
                if (dp[i+1][j-1] == 1 && s[i] == s[j]) dp[i][j] = 1;
            }
        }
        
        vector<int> res(len,100000);
        int tmp;
        for (int i = 0; i < len; i++) {
            if (dp[0][i] == 1) res[i] = 0;
            else {
                for (int k = 0; k < i; k++) {
                    if (dp[k+1][i] == 1) tmp = 1 + res[k];
                    else tmp = res[k] + i - k;
                    res[i] = min(res[i], tmp);
                }
            }
        }
        return res[len-1];
    }
};
