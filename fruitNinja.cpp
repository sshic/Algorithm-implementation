/* zoj3638 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=25;
const int Mod=100000007;

int Power(int x,int cf){
  if(cf==0) return 1;
  long long ret=Power(x,cf>>1);
  ret=ret*ret%Mod;
  if(cf&1) ret=ret*x%Mod;
  return ret;
}

long long C(int m,int n){  
  if(n<0||n>m||m<0) return 0;
  long long up=1;
  long long down=1;
  for(int i=m-n+1;i<=m;i++) up=up*i%Mod;
  for(int i=1;i<=n;i++) down=down*i%Mod;
  return up*Power(down,Mod-2)%Mod;
}

int n,m,s;
char Str[100];
char s1[100];
char s2[100];
int a[N];
long long ans;

void dfs(int p,int sum,int t){
  if (sum<1) return;
  if (p>m) {
    if(t&1) ans-=C(sum-1,n-1);
    else ans+=C(sum-1,n-1);
    ans=(ans%Mod+Mod)%Mod;
    return;
  }
  dfs(p+1,sum,t);
  dfs(p+1,sum-a[p],t+1);
}

int main(){
  while(scanf("%d%d",&n,&s)!=EOF){
    if (n==0) break;
    gets(Str);
    m=0;
    s+=n;
    bool check=true;
    while(1){
      if(!gets(Str)) break;
      if(strlen(Str)<2) break;
      int Num;
      sscanf(Str,"%s%s%s%d",s1,s1,s2,&Num);
      Num++;
      if(s1[0]=='l') {
        a[++m]=Num-1;
	if(Num==1) check=false;
      }
      else s-=Num;
    }
    if(!check) printf("0ff\n");
    else{
      ans=0;
      dfs(1,s,0);
      printf("%d\n",ans);
    }
  }
}
