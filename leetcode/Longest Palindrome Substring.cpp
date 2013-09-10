#664 mili secs for large data set
#Iteratative is much faster than Recursive
#Prune

class Solution {
public:
    string str;
    bool isPalindrome(int i,int j){
        while(i<j){
            if(str[i]!=str[j])
                return false;
            ++i;--j;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string result;
        str=s;
        int i,j;
        for(i=0;i<s.length();i++){
            for(j=0;j<=i;j++){
                if(isPalindrome(j,i)||(i-j+1)<=result.length())
                    break;
            }
            if((i-j+1)>result.length())
                result=s.substr(j,i-j+1);
        }
        return result;
    }
};