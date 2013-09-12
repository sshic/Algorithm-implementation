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

