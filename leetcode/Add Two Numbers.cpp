/** * Definition for singly-linked list. * struct ListNode { *     int val; *     ListNode *next; *     ListNode(int x) : val(x), next(NULL) {} * }; */ #204 mili secs for large data set class Solution {public:    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {        ListNode *n1=l1,*n2=l2;        int flag=0,sum=0;        while(n1!=NULL&&n2!=NULL){            sum=flag+n1->val+n2->val;            n1->val=sum%10;            flag=sum/10;            n1=n1->next;            n2=n2->next;        }        while(n1!=NULL){            sum=flag+n1->val;            n1->val=sum%10;            flag=sum/10;            n1=n1->next;        }        if(n2!=NULL){            n1=l1;            while(n1!=NULL&&n1->next!=NULL)                n1=n1->next;            n1->next=n2;            while(n2!=NULL&&flag!=0){                sum=flag+n2->val;                n2->val=sum%10;                flag=sum/10;                n2=n2->next;            }        }        if(flag!=0){            n1=l1;            while(n1->next!=NULL)                n1=n1->next;            ListNode *t=new ListNode(flag);            n1->next=t;        }        return l1;    }};