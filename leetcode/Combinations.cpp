class Solution {
public:
    vector<vector<int> > result;
    void f(vector<int> p,int n,int k,int i){
        if(p.size()==k){
            result.push_back(p);
            return;//容易出错的地方
        }
        if(i>n)
            return;
        f(p,n,k,i+1);
        p.push_back(i);
        f(p,n,k,i+1);
        return;
    }
    vector<vector<int> > combine(int n, int k) {
        result.clear();
        vector<int> t;
        f(t,n,k,1);
        return result;
    }
};