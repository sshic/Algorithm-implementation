class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        int len1=num1.length(),len2=num2.length();
        int flag=0,t;
        vector<string> re;
        for(int i=len2-1;i>=0;i--){
            string str="";
            flag=0;
            for(int k=len2-1;k>i;k--)
                str+='0';
            for(int j=len1-1;j>=0;j--){
                t=flag+(num1[j]-'0')*(num2[i]-'0');
                str+=t%10+'0';
                flag=t/10;
            }
            if(flag!=0)
                str+=flag+'0';
            re.push_back(str);
        }
        string result="";
        bool f=true;
        int cnt=0;
        flag=0;
        while(f){
            f=false;
            for(int i=0;i<re.size();i++){
                if(cnt<re[i].length()){
                    f=true;
                    flag+=re[i][cnt]-'0';
                }
            }
            if(f||flag!=0)
                result+=flag%10+'0';
            flag=flag/10;
            ++cnt;
        }
        int first=0,last=result.length()-1;
        char tmp;
        while(first<last){
            tmp=result[first];
            result[first]=result[last];
            result[last]=tmp;
            ++first,--last;
        }
        return result;
    }
};