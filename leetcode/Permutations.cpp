class Solution {public:    int n;    int visit[100];    vector<vector<int> > result;    vector<int> numm;    void recur(vector<int> t,int cnt){        if(cnt==n){            result.push_back(t);            return;        }        for(int i=0;i<n;i++){            if(visit[i]==0){                visit[i]=1;              //  cout<<i<<endl;                t.push_back(numm[i]);                recur(t,cnt+1);                t.pop_back();                visit[i]=0;            }        }        return;    }    vector<vector<int> > permute(vector<int> &num) {        n=num.size();        result.clear();        numm=num;        if(n==0)            return result;        memset(visit,0,sizeof(visit));        vector<int> v;        recur(v,0);        return result;    }};