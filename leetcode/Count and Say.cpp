#8 mili secs for large data set

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string s = "1";
        for(int ir = 2; ir <= n; ++ir) {
            string t;
            for(int i = 0; i < s.size(); ++i) {
                char curc = s[i];
                int countc = 1;
                for(int j = i + 1; j < s.size() && s[j] == curc; ++j) {
                    ++countc;
                    ++i;
                }
                t += ('0' + countc);
                t += curc;
            }
            s = t;
        }
        return s;
    }
};