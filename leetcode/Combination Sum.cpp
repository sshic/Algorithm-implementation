#200 mili secs for large data set

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int len=candidates.size();
        vector<vector<int> > result;
        if(len==0)
            return result;
        sort(candidates.begin(),candidates.end());
        int f=0;
        vector<pair<vector<int>,int> > tmp;
        vector<int> t;
        while(f<=target){
            tmp.push_back(make_pair(t,f));
            t.push_back(candidates[0]);
            f+=candidates[0];
        }

        for(int i=1;i<len;i++){
            int s=tmp.size();
            for(int j=0;j<s;j++){
                f=tmp[j].second;
                t=tmp[j].first;
                while(f+candidates[i]<=target){
                    f+=candidates[i];
                    t.push_back(candidates[i]);
                    tmp.push_back(make_pair(t,f));
                }
            }
        }

        for(int i=0;i<tmp.size();i++){
            if(tmp[i].second==target)
                result.push_back(tmp[i].first);
        }
        return result;
    }
};