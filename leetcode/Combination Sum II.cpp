#120 mili secs for large data set

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        if(num.size()==0)  return result;
        sort(num.begin(),num.end());
        vector<pair<int,int> > num2;
        num2.push_back(make_pair(num[0],1));
        for(int i=1;i<num.size();i++){
            if(num[i]==num[i-1])
                ++num2[num2.size()-1].second;
            else
                num2.push_back(make_pair(num[i],1));
        }
        int f=0;
        vector<pair<vector<int>,int> > tmp;
        vector<int> t;
        while(f/num2[0].first<=num2[0].second&&f<=target){
            tmp.push_back(make_pair(t,f));
            f+=num2[0].first;
            t.push_back(num2[0].first);
        }

        for(int i=1;i<num2.size();i++){
            int s=tmp.size();
            for(int j=0;j<s;j++){
                f=tmp[j].second;
                t=tmp[j].first;
                while((f-tmp[j].second)/num2[i].first<num2[i].second&&f+num2[i].first<=target){
                    f+=num2[i].first;
                    t.push_back(num2[i].first);
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