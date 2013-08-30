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
    vector<int > in;
    void inorder(TreeNode * root){
        if(root==NULL)
            return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
        return ;
    }
    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
        inorder(root);
        int i=0,j=in.size()-1;
        while(i<j){
            if(in[i]!=in[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};
int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    t1.right=&t2;
    //TreeNode t3(2);
    //t1.right=&t3;
    //TreeNode t4(4);
    //t2.left=&t4;

    vector<int> in;
    in.push_back(2);
    in.push_back(1);
    in.push_back(3);

    vector<int> post;
    post.push_back(1);
    post.push_back(2);
    post.push_back(3);

    Solution s;
    bool t=s.isSymmetric(&t1);
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
