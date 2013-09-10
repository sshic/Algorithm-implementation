#88 mili secs for large data set

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result=0;
        int alpha[33];
        int t=0;
        for(int i=0;i<s.length();i++){
            int j=i;
            t=0;
            memset(alpha,0,sizeof(alpha));
            while(j<s.length()&&alpha[s[j]-'a']==0){
                alpha[s[j]-'a']=1;
                ++t;
                ++j;
            }
            if(t>result)
                result=t;
        }
        return result;
    }
};