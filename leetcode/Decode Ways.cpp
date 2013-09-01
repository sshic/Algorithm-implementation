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
    int numDecodings(string s) {
        vector<int> result;
        if(s.size()==0||s[0]=='0')
            return 0;
        result.push_back(1);
        result.push_back(1);
        for(int i=2;i<=s.length();i++){
            int t=0;
            if(s[i-1]!='0')
                t+=result[i-1];
            int t1=(s[i-2]-'0')*10+(s[i-1]-'0');
            if(t1<=26&&t1>9)
                t+=result[i-2];
            result.push_back(t);
        }
        for(int i=0;i<result.size();i++)
            cout<<result[i]<<endl;
        return result[s.length()];
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
    int f=s.numDecodings("11");
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
