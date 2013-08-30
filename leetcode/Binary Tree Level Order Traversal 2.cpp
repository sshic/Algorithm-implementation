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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        int height=1;
        int num=1,i,j;
        vector<vector<int > > result;
        if(root==NULL)
            return result;
        vector<TreeNode *> q1,q2;
        q1.push_back(root);
        vector<int> t;
        t.push_back(root->val);
        result.push_back(t);
        while(true){
            t.clear();
            if(height%2==1&&q1.size()!=0){
                q2.clear();
                for(i=0;i<q1.size();i++){
                    if(q1[i]->left!=NULL)
                        q2.push_back(q1[i]->left);
                    if(q1[i]->right!=NULL)
                        q2.push_back(q1[i]->right);
                }

                for(j=0;j<q2.size();j++){
                    t.push_back(q2[j]->val);
                }
                if(t.size()!=0)
                    result.push_back(t);
                ++height;
            }
            else if(height%2==0&&q2.size()!=0){
                q1.clear();
                for(i=0;i<q2.size();i++){
                    if(q2[i]->left!=NULL)
                        q1.push_back(q2[i]->left);
                    if(q2[i]->right!=NULL)
                        q1.push_back(q2[i]->right);
                }
                for(j=0;j<q1.size();j++){
                    t.push_back(q1[j]->val);
                }
                if(t.size()!=0)
                    result.push_back(t);
                ++height;
            }
            else break;
        }
        vector<vector<int > > re;
        for(i=result.size()-1;i>=0;i--){
            t.clear();
            for(j=0;j<result[i].size();j++)
            {
                t.push_back(result[i][j]);
            }
            re.push_back(t);
        }
        return re;
    }
};
int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    t1.left=&t2;
    TreeNode t3(3);
    t1.right=&t3;
    //TreeNode t4(0);
    /*
    vector<int> in;
    in.push_back(1);
    in.push_back(2);
    in.push_back(3);
    */
    Solution s;
    vector<vector<int > > f=s.levelOrderBottom(&t1);
    for(int i=0;i<f.size();i++){
        for(int j=0;j<f[i].size();j++)
        {
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
