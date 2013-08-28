#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
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
    bool dfs(TreeNode *p,TreeNode *q){
        if(p==NULL&&q!=NULL)
            return false;
        if(p!=NULL&&q==NULL)
            return false;
        if(p!=NULL&&q!=NULL&&p->val!=q->val)
            return false;
        if((p==NULL)&&(q==NULL)){
            return true;
        }
        return dfs(p->left,q->left)&&dfs(p->right,q->right);
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL&&q==NULL)
            return true;
        if(p==NULL||q==NULL)
            return false;
        return dfs(p,q);
    }
};
int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    t1.right=&t2;
    TreeNode t3(1);
    //t1.right=&t3;
    TreeNode t4(3);
    t3.right=&t4;

    vector<int> in;
    in.push_back(2);
    in.push_back(1);
    in.push_back(3);

    vector<int> post;
    post.push_back(1);
    post.push_back(2);
    post.push_back(3);

    Solution s;
    bool t=s.isSameTree(&t1,&t3);
    if(t)
        cout<<"true"<<endl;
    else cout<<"false"<<endl;
  /*  for(int i=0;i<f.size();i++){
        for(int j=0;j<f[i].size();j++)
        {
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }

    */
    return 0;
}
