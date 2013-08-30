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
    vector<TreeNode *> in;
    void inorder(TreeNode * root){
        if(root==NULL)
            return;
        inorder(root->left);
        in.push_back(root);
        inorder(root->right);
        return ;
    }
    void recoverTree(TreeNode *root) {
        if(root==NULL)
            return;
        in.clear();
        TreeNode *n1=NULL;
        TreeNode *n2=NULL;
        inorder(root);
        bool flag=false;
        for(int i=0;i<in.size()-1;i++){
            if(in[i]->val>in[i+1]->val){
                n1=in[i];
                break;
            }
        }
        for(int i=1;i<in.size();i++){
            if(in[i]->val<in[i-1]->val){
                n2=in[i];
               // break;   Attention!!
            }
        }
        int tmp=n1->val;
        n1->val=n2->val;
        n2->val=tmp;
        TreeNode * re=root;
        while(re){
            cout<<re->val<<endl;
            re=re->left;
        }
        return;
    }
};
int main(){
    TreeNode t1(2);
    TreeNode t2(1);
    t1.right=&t2;
    TreeNode t3(3);
    t1.left=&t3;
    //TreeNode t4(3);
    //t3.right=&t4;

    vector<int> in;
    in.push_back(2);
    in.push_back(1);
    in.push_back(3);

    vector<int> post;
    post.push_back(1);
    post.push_back(2);
    post.push_back(3);

    Solution s;
    s.recoverTree(&t1);

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
