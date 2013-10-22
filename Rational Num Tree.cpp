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
    unsigned long long m,n,sum,p,q;
    int num,tag;
    cin>>num;
    for(int i=1;i<=num;i++){
        cin>>tag>>m;
        if(tag==2)
            cin>>n;
        if(tag==1){
            p=1;q=1;
            vector<int> change;
            while(m!=1){
                if(m%2==1){
                    change.push_back(1);
                    m=(m-1)/2;
                }
                else{
                    change.push_back(0);
                    m/=2;
                }
            }
            for(int j=change.size()-1;j>=0;j--){
                if(change[j]==1){
                    p=p+q;
                }
                else
                    q=p+q;
            }
            fputs("Case #",fp);
            fprintf(fp,"%d",i);
            fputs(": ",fp);
            fprintf(fp,"%llu %llu\n",p,q);
        }
        else if(tag==2){
            sum=1;
            vector<int> change;
            while(m!=1||n!=1){
                if(m>n){
                    change.push_back(1);
                    m=m-n;
                }
                else{
                    change.push_back(0);
                    n=n-m;
                }
            }
            for(int j=change.size()-1;j>=0;j--){
                if(change[j]==1){
                    sum=sum*2+1;
                }
                else
                    sum*=2;
            }
            fputs("Case #",fp);
            fprintf(fp,"%d",i);
            fputs(": ",fp);
            fprintf(fp,"%llu\n",sum);
        }
    }
    return 0;
}
