#80 mili secs for large data setclass Solution {public:    string convert(string s, int nRows) {        if(nRows <= 1) return s;        string ret;        int zigsize = 2 * nRows - 2;        for(int i = 0; i < nRows; ++i) {            for(int base = i; ;base += zigsize) {                if(base >= s.size())                    break;                ret.append(1,s[base]);                if(i > 0 && i < nRows - 1) {                    int ti = base + zigsize - 2 * i;                    if(ti < s.size())                        ret.append(1,s[ti]);                }            }        }        return ret;    }};