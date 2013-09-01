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
    int alphaT[100],str[100];
    int first,second,t,sLen,tLen;
    string minWindow(string S, string T) {
        string result="";
        first=0,second=0,t=0,sLen=S.length(),tLen=T.length();
        if(T.length()==1){
            for(int i=0;i<S.length();i++){
                if(S[i]==T[0]){
                    return T;
                }
            }
        }
        if(sLen<tLen)
            return result;
        for(int j=0;j<100;j++)
            alphaT[j]=0,str[j]=0;
        for(int j=0;j<tLen;j++)
            ++alphaT[T[j]-'A'];
        while(first<sLen){
            //Find first
            while(t<tLen&&first<sLen){
                if(alphaT[S[first]-'A']!=0){
                    if(alphaT[S[first]-'A']>str[S[first]-'A'])
                        ++t;
                    ++str[S[first]-'A'];
                }
                ++first;
            }
            string ss;
            //Find second
            while(t==tLen&&second<sLen){
                if(alphaT[S[second]-'A']!=0){
                    --str[S[second]-'A'];
                    if(alphaT[S[second]-'A']>str[S[second]-'A']){
                        ss=S.substr(second,first-second);
                        if(result==""||result.length()>ss.length())
                            result=ss;
                        --t;
                    }
                }
                ++second;
            }
            //cout<<first<<"----"<<second<<endl;
        }
        return result;
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
    cout<<s.minWindow("bdab","ab")<<endl;
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
