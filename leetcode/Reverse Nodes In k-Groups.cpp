/** * Definition for singly-linked list. * struct ListNode { *     int val; *     ListNode *next; *     ListNode(int x) : val(x), next(NULL) {} * }; */#132 mili secs for large data set class Solution {public:    ListNode *reverseKGroup(ListNode *head, int k) {        int cnt,num=0;        if(head==NULL) return head;        ListNode *pre=head,*cur=head->next,*h;        while(pre!=NULL){            pre=pre->next;            ++num;        }        if(num<k)            return head;        pre=new ListNode(0);        pre->next=head;        h=pre;        num=num/k;        for(int i=0;i<num;i++){            if(i!=0)                h=pre;            pre=h->next;            cur=pre->next;            cnt=1;            while(cur!=NULL&&cnt<k){                pre->next=cur->next;                cur->next=h->next;                h->next=cur;                cur=pre->next;                ++cnt;            }            if(i==0)                head=h->next;        }        return head;    }};