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
    int dfs(TreeNode *root){
        if(root==NULL)
            return 0;
        int t1=dfs(root->left)+1;
        int t2=dfs(root->right)+1;
        return t1>t2 ? t1:t2;
    }
    int maxDepth(TreeNode *root) {
        return dfs(root);
    }
};
int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    t1.left=&t2;
    TreeNode t3(3);
    t1.right=&t3;
    TreeNode t4(4);
    t2.left=&t4;

    vector<int> in;
    in.push_back(2);
    in.push_back(1);
    in.push_back(3);

    vector<int> post;
    post.push_back(1);
    post.push_back(2);
    post.push_back(3);

    Solution s;
    int t=s.maxDepth(&t1);
    cout<<t<<endl;
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
