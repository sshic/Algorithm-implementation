#include <iostream>
#include <vector>
#include <cstring>
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
    TreeNode * buildBST(ListNode *root,int num){
        if(num==0)
            return NULL;
        if(num==1){
            TreeNode *tmp=new TreeNode(root->val);
            return tmp;
        }
        ListNode *mid=root;
        int c=num/2;
        while(c>0){
            mid=mid->next;
            --c;
        }
        TreeNode *t=new TreeNode(mid->val);
        t->left=buildBST(root,num/2);
        t->right=buildBST(mid->next,num-num/2-1);
        return t;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL)
            return NULL;
        int cnt=0;
        ListNode * visit=head;
        while(visit){
            visit=visit->next;
            ++cnt;
        }
        return buildBST(head,cnt);
    }
};
int main(){
    ListNode t1(1);
    ListNode t2(2);
    t1.next=&t2;
    ListNode t3(3);
    t2.next=&t3;
    ListNode t4(0);
    Solution s;
    TreeNode * f=s.sortedListToBST(&t1);
    while(f){
        cout<<f->val<<endl;
        f=f->right;
    }
    return 0;
}
