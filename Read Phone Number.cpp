#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    freopen("test_in.txt","r",stdin);
    FILE *fp=fopen("Moist.out","w");
    int num;
    string str,s;
    vector<int> sep;
    vector<string> result;
    cin>>num;
    string digits[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    string numbers[]={"","","double","triple","quadruple","quintuple","sextuple","septuple","octuple","nonuple","decuple"};
    for(int i=1;i<=num;i++){
        cin>>str>>s;
        sep.clear();
        result.clear();
        int sepNum=0;
        for(int j=0;j<s.length();j++){
            if(s[j]=='-'){
                sep.push_back(sepNum);
                sepNum=0;
            }
            else{
                sepNum=sepNum*10+(s[j]-'0');
            }
        }
        sep.push_back(sepNum);
        int k=0,l,cnt;
        for(int j=0;j<sep.size();j++){
            l=k,cnt=1;
            while(l<k+sep[j]){
                if(l+1<k+sep[j]&&str[l+1]==str[l])
                    ++cnt;
                else{
                    if(cnt>10){
                        while(cnt--)
                            result.push_back(digits[str[l]-'0']);
                    }
                    else{
                        if(numbers[cnt]!="")
                            result.push_back(numbers[cnt]);
                        result.push_back(digits[str[l]-'0']);
                    }
                    cnt=1;
                }
                ++l;
            }
            k+=sep[j];
        }
        string rr="";
        for(int j=0;j<result.size()-1;j++){
            rr+=result[j];
            rr+=' ';
        }
        rr+=result[result.size()-1];
        fputs("Case #",fp);
        fprintf(fp,"%d",i);
        fputs(": ",fp);
        fprintf(fp,"%s\n",rr.c_str());
    }
    return 0;
}
