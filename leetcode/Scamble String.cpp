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
    bool isScramble(string s1, string s2) {
       // cout<<s1<<" "<<s2<<endl;
        if(s1.length()!=s2.length())
            return false;
        int len=s1.length();
        if(s1==s2)
            return true;
        string ts1=s1,ts2=s2;
        sort(ts1.begin(),ts1.end());
        sort(ts2.begin(),ts2.end());
        if(ts1!=ts2)
            return false;
        for(int i=1;i<len;i++)  {
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&&
                isScramble(s1.substr(i,len-i),s2.substr(i,len-i)))
                return true;
            if(isScramble(s1.substr(0,i),s2.substr(len-i,i))&&
                isScramble(s1.substr(i,len-i),s2.substr(0,len-i)))
                return true;
        }
        return false;
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
    bool f=s.isScramble("abcdefghijklmnopq","efghijklmnopqcadb");
    if(f)
        cout<<"true"<<endl;
    else cout<<"false"<<endl;
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
