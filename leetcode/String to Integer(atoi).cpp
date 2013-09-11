#48 milli secs for large data set

class Solution {
public:
    int atoi(const char *str) {
        static long long MAX=2147483647;
        static long long MIN=2147483648;
        long long result=0;
        int flag=0;
        while(*str!='\0'){
            while(*str==' ')
                ++str;
            if(*str=='+'||*str=='-'||(*str>='0'&&*str<='9')){
                if(*str=='+')
                    ++str;
                else if(*str=='-'){
                    flag=1;
                    ++str;
                }
                while(*str>='0'&&*str<='9'){
                    result=result*10+(*str-'0');
                    ++str;
                }
                if(flag==0&&result>MAX)
                    result=MAX;
                if(flag==1&&result>MIN)
                    result=MIN;
                return flag? result*(-1):result;
            }
            else return result;
        }
        return result;
    }
};