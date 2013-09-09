#32 mili secs for large data set

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *h=head,*t=head;
        for(int i=0;i<n;i++)
            t=t->next;
        if(t==NULL)
            return head->next;
        while(t->next!=NULL){
            t=t->next;
            h=h->next;
        }
        h->next=h->next->next;
        return head;
    }
};