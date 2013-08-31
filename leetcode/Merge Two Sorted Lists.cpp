/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *n1=l1, *n2=l2, *head, *cur;
        head=new ListNode(0);
        cur=head;
        while(n1!=NULL&&n2!=NULL){
            if(n1->val<n2->val){
                cur->next=n1;
                cur=cur->next;
                n1=n1->next;
            }
            else{
                cur->next=n2;
                cur=cur->next;
                n2=n2->next;
            }
        }
        while(n1!=NULL){
            cur->next=n1;
            cur=cur->next;
            n1=n1->next;
        }
        while(n2!=NULL){
            cur->next=n2;
            cur=cur->next;
            n2=n2->next;
        }
        cur->next=NULL;
        return head->next;
    }
};