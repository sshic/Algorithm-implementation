class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int cnt=1;
        ListNode *h=head;
        vector<int > changeArea;
        while(h&&cnt<m){
            h=h->next;
            ++cnt;
        }
        ListNode *h1=h;
        while(h1&&cnt<=n){
            changeArea.push_back(h1->val);
            h1=h1->next;
            ++cnt;
        }
        int i=changeArea.size();
        while(h!=h1){
            h->val=changeArea[--i];
            h=h->next;
        }
        return head;
    }
};