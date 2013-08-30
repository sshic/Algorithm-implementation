#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > result;
    vector<int> s,cnt;
    void dp(vector<int> ss,int n){
        if(n==s.size()){

            result.push_back(ss);
            return;
        }
        dp(ss,n+1);
        for(int i=1;i<=cnt[n];i++){
            ss.push_back(s[n]);
            dp(ss,n+1);
        }
        return;
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        result.clear();
        s.clear();
        cnt.clear();
        if(S.size()==0){
            result.push_back(S);
            return result;
        }
        sort(S.begin(),S.end());
        cnt.push_back(1);
        s.push_back(S[0]);
        for(int i=1;i<S.size();i++){
            if(S[i]!=S[i-1]){
                s.push_back(S[i]);
                cnt.push_back(1);
            }
            else
                ++cnt[cnt.size()-1];
        }
        vector<int> tmp;
        dp(tmp,0);
        return result;
    }
};
int main(){
    ListNode t1(2);
    ListNode t2(1);
    t1.next=&t2;
    ListNode t3(3);
    t2.next=&t3;
    //TreeNode t4(3);
    //t3.right=&t4;

    vector<int> in;
    in.push_back(1);
    in.push_back(2);
    in.push_back(2);

    vector<int> post;
    post.push_back(1);
    post.push_back(2);
    post.push_back(3);

    Solution s;
    vector<vector<int> > f=s.subsetsWithDup(in);
    for(int i=0;i<f.size();i++)
    {
        for(int j=0;j<f[i].size();j++)
        {
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
