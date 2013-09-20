#include <iostream>

class Solution {
public:
    int alphaT[100],str[100];
    int first,second,t,sLen,tLen;
    string minWindow(string S, string T) {
        string result="";
        first=0,second=0,t=0,sLen=S.length(),tLen=T.length();
        if(T.length()==1){
            for(int i=0;i<S.length();i++){
                if(S[i]==T[0]){
                    return T;
                }
            }
        }
        if(sLen<tLen)
            return result;
        for(int j=0;j<100;j++)
            alphaT[j]=0,str[j]=0;
        for(int j=0;j<tLen;j++)
            ++alphaT[T[j]-'A'];
        while(first<sLen){
            //Find first
            while(t<tLen&&first<sLen){
                if(alphaT[S[first]-'A']!=0){
                    if(alphaT[S[first]-'A']>str[S[first]-'A'])
                        ++t;
                    ++str[S[first]-'A'];
                }
                ++first;
            }
            string ss;
            //Find second
            while(t==tLen&&second<sLen){
                if(alphaT[S[second]-'A']!=0){
                    --str[S[second]-'A'];
                    if(alphaT[S[second]-'A']>str[S[second]-'A']){
                        ss=S.substr(second,first-second);
                        if(result==""||result.length()>ss.length())
                            result=ss;
                        --t;
                    }
                }
                ++second;
            }
            //cout<<first<<"----"<<second<<endl;
        }
        return result;
    }
};

//better
class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = S.size();
        int n = T.size();
        
        vector<int> TC(256);
        
        for (int i = 0; i < n; i++)
            TC[T[i]]++;
        
        int chs = 0;
        
        for (int i = 0; i < 256; i++)
            if (TC[i]) chs++;
        
        int pos = 0;
        int len = INT_MAX;
        
        int i = 0;
        for (int j = 0; j < m; j++) {
            char ch = S[j];
            TC[ch]--;
            
            if (TC[ch] == 0) chs--;
            
            while (TC[S[i]] < 0) {
                TC[S[i]]++;
                i++;
            }
            
            if (chs == 0 && j - i + 1 < len) {
                len = j - i + 1;
                pos = i;
            }
        }
        
        return len == INT_MAX ? "" : S.substr(pos, len);
    }
};