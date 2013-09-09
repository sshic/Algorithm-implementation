class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(needle==NULL||haystack==NULL)
            return NULL;
        char *hh=haystack,*nn=needle;
        string h="",n="";
        while(*hh!='\0'){
            h+=*hh;
            ++hh;
        }
        while(*nn!='\0'){
            n+=*nn;
            ++nn;
        }
        if(n=="")
            return haystack;
        string str;
        for(int i=0;i<h.length();i++){
            str=h.substr(i,n.length());
            if(str==n)
                return haystack+i;
        }
        return NULL;
    }
};