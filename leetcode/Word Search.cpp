#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <stack>
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
    vector<vector<char> > boa;
    int visit[100][100];
    string target;
    int r,c;
    bool dp(int m,int n,int num){
        if(boa[m][n]!=target[num])
            return false;
        if(num==target.length()-1)
            return true;
        visit[m][n]=1;
        if(m>0&&!visit[m-1][n]&&dp(m-1,n,num+1))
            return true;
        if(m<r-1&&!visit[m+1][n]&&dp(m+1,n,num+1))
            return true;
        if(n>0&&!visit[m][n-1]&&dp(m,n-1,num+1))
            return true;
        if(n<c-1&&!visit[m][n+1]&&dp(m,n+1,num+1))
            return true;
        visit[m][n]=0;
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        boa=board;
        target=word;
        r=board.size();
        c=board[0].size();
        memset(visit,0,sizeof(visit));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(dp(i,j,0))
                    return true;
            }
        }
        return false;
    }
};
int main(){
    ListNode t1(1);
    ListNode t2(2);
    t1.next=&t2;
    ListNode t3(3);
   // t2.next=&t3;
    //TreeNode t4(3);
    //t3.right=&t4;

    vector<int> in;
    in.push_back(1);
    in.push_back(3);
 /*   in.push_back(1);
    in.push_back(0);
    in.push_back(1);
    in.push_back(3);

    vector<int> post;
    post.push_back(1);
    post.push_back(2);
    post.push_back(3);
*/
    int inn[2];
    inn[0]=1;
    inn[1]=3;
    Solution s;
    cout<<s.search1(inn,2,3)<<endl;
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
