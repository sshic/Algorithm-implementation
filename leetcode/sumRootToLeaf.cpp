#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sum;
    vector<TreeNode *> path;
    void dfs(TreeNode *root){
        if(root->left==NULL && root->right==NULL){
            int tmp=0;
            for(int i=0;i<path.size();i++){
                tmp = tmp*10+path[i]->val;
            }
            sum += tmp;
            return;
        }
        else{
            if(root->left!=NULL){
                path.push_back(root->left);
                dfs(root->left);
                path.pop_back();
            }
            if(root->right!=NULL){
                path.push_back(root->right);
                dfs(root->right);
                path.pop_back();
            }
        }
    }

    int sumNumbers(TreeNode *root){
        sum = 0;
        if(root==NULL)
            return 0;
        path.clear();
        path.push_back(root);
        dfs(root);
        return sum;
    }
};

int main(){
    Solution sol;
    TreeNode *root = new TreeNode(4);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(0);
    TreeNode *node3 = new TreeNode(1);
 //   TreeNode *node4 = new TreeNode(5);
    root->left = node1;
    root->right = node2;
   // node1->left = node3;
    node1->right = node3;

    cout<<sol.sumNumbers(root)<<endl;
    return 0;
}
