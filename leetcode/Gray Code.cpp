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
    vector<int> t;
    int nn,cf;
    void code(int m){
        if(m>nn)
            return;
        for(int i=t.size()-1;i>=0;i--){
            t.push_back(t[i]+cf);
        }
        cf*=2;
        code(m+1);
        return;
    }
    vector<int> grayCode(int n) {
        t.clear();
        nn=n;
        cf=1;
        t.push_back(0);
        if(n==0)
            return t;
        code(1);
        return t;
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
    vector<int> f=s.grayCode(1);
    for(int j=0;j<f.size();j++)
    {
        cout<<f[j]<<" ";
    }
    //cout<<f<<endl;
 /*   for(int i=0;i<f.size();i++)
    {
        for(int j=0;j<f[i].size();j++)
        {
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
   */
    return 0;
}
