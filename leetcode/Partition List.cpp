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
    ListNode *partition(ListNode *head, int x) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode * n1=new ListNode(0);
        n1->next=head;
        bool flag=false;
        while(n1->next->val<x)
            n1=n1->next;
        if(n1->next==head)
            flag=true;
        ListNode * n2=head;
        ListNode * n3=n1;
        n2=n1->next;
        while(n2&&n2->next){
            if(n2->next->val<x){
                ListNode * newNode=new ListNode(n2->next->val);
                newNode->next=n3->next;
                n3->next=newNode;
                n3=n3->next;
                n2->next=n2->next->next;
            }
            else
                n2=n2->next;
        }
        if(flag)
            return n1->next;
        else return head;
    }
};
int main(){
    ListNode t1(1);
    ListNode t2(1);
    t1.next=&t2;
    ListNode t3(3);
  //  t2.next=&t3;
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
    ListNode * f=s.partition(&t1,2);
    while(f){
        cout<<f->val<<endl;
        f=f->next;
    }

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
