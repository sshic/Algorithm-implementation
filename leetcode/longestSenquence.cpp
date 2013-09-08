#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        bool isNum[4000000001];
        for(int i=0;i<4000000001;i++){
            isNum[i] = false;
        }
        for(int i=0;i<num.size();i++){
            isNum[num[i]] = true;
        }
        int maxConsecutive = 0;
        int tmp;
        for(int i=0;i<num.size();i++){
            if(isNum[num[i]]==true){
                ++tmp;
                int f = num[i];
                while(isNum[++f]){
                    ++tmp;
                    isNum[f] = false;
                }
                f = num[i];
                while(isNum[--f]){
                    ++tmp;
                    isNum[f] = false;
                }
            }
            if(isNum[i]==false && tmp!=0){
                if(maxConsecutive<tmp)
                    maxConsecutive = tmp;
                tmp = 0;
            }
        }
        return maxConsecutive;
    }
};

int main(){
    Solution sol;
    vector<int> n;
    n.push_back(100);
    n.push_back(4);
    n.push_back(200);
    n.push_back(3);
    n.push_back(1);
    n.push_back(2);
    cout<<sol.longestConsecutive(n)<<endl;
    return 0;
}
