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

public:
    int largestRectangleArea(vector<int> &height) {
        int max_area=0,t;
        vector<int> stackH;
        for(int i=0;i<height.size();i++){
            if(stackH.size()==0||height[i]>=height[stackH.back()]){
                stackH.push_back(i);
            }
            else{
                if(stackH.size()==1)
                    t=height[stackH.back()]*i;
                else
                    t=height[stackH.back()]*(i-stackH[stackH.size()-2]-1);
                stackH.pop_back();
                if(max_area<t)
                    max_area=t;
                --i;
            }
        }

        if(stackH.size()!=0&&height[stackH[0]]*height.size()>max_area)
            max_area=height[stackH[0]]*height.size();
        for(int i=1;i<stackH.size();i++){
            t=height[stackH[i]]*(stackH[stackH.size()-1]-stackH[i-1]);
            if(max_area<t)
                max_area=t;
        }
        return max_area;
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
    in.push_back(0);
    in.push_back(1);
    in.push_back(0);
    in.push_back(1);
/*    in.push_back(3);

    vector<int> post;
    post.push_back(1);
    post.push_back(2);
    post.push_back(3);
*/
    Solution s;
    cout<<s.largestRectangleArea(in)<<endl;
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
