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
    string str;
    vector<string> result;
    bool illegal(string s){
        int le=0;
        if(s[0]=='0'&&s.length()==1)
            return true;
        if(s[0]=='0')
            return false;
        for(int i=0;i<s.length();i++){
            le=le*10+(s[i]-'0');
        }
        if(le<=255)
            return true;
        else return false;
    }
    void dp(string s,int pos,int num){
        if(pos>str.length()-1)
            return;
        if(num==4){
            if(illegal(str.substr(pos,str.length()-pos))){
                s+=".";
                s+=str.substr(pos,str.length()-pos);
                result.push_back(s);
            }
            return;
        }

        for(int i=1;i<=3;i++){
            if(illegal(str.substr(pos,i))){
                string ss=s;
                if(num!=1)
                    ss+=".";
                ss+=str.substr(pos,i);
                //cout<<ss<<endl;
                dp(ss,pos+i,num+1);
            }
        }
        return ;
    }
    vector<string> restoreIpAddresses(string s) {
        str=s;
        result.clear();
        if(s.length()<4||s.length()>12)
            return result;
        dp("",0,1);
        return result;
    }
};
int main(){
    ListNode t1(2);
    ListNode t2(1);
    t1.next=&t2;
    ListNode t3(3);
    t2.next=&t3;
    //TreeNode t4(3);
    //t3.right=&t4;

    vector<int> in;
    in.push_back(2);
    in.push_back(1);
    in.push_back(3);

    vector<int> post;
    post.push_back(1);
    post.push_back(2);
    post.push_back(3);

    Solution s;
    vector<string> f=s.restoreIpAddresses("2736786374048");
    for(int i=0;i<f.size();i++)
        cout<<f[i]<<endl;
    return 0;
}
