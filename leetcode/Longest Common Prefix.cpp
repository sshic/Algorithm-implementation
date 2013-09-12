#36 milli secs for large data set

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size()==0)
            return "";
        int l=0;
        char c;
        while(l<strs[0].length()){
            c=strs[0][l];
            for(int i=1;i<strs.size();i++){
                if(l>=strs[i].length()||strs[i][l]!=c)
                    return strs[0].substr(0,l);
            }
            ++l;
        }
        return strs[0].substr(0,l);
    }
};