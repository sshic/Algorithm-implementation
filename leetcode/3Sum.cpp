#264 milli secs for large data setclass Solution {public:    vector<vector<int> > threeSum(vector<int> &num) {        sort(num.begin(),num.end());        vector<vector<int> >res;        vector<int> t;        int cki,ckj;        int n = num.size();        if(n<3)return res;        cki=ckj=num[0]-1;        for(int i=0;i<n-2 && num[i]<=0;++i){           if(i>0 && num[i]==num[i-1])continue;             int j= i+1;            int k= n-1;            while(j<k){                int sum_2=num[i]+num[j];                if(sum_2+num[k]<0)                    ++j;                else if(sum_2+num[k]>0)                    k--;                else if(cki<num[i] || ckj!=num[j]){                    t.clear();                    t.push_back(num[i]);                    t.push_back(num[j]);                    t.push_back(num[k]);                    cki=num[i];                    ckj=num[j];                    res.push_back(t);                    ++j;--k;                }                else{                    ++j;--k;                }            }        }        return res;    }};