#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int dist(string s1,string s2){
        int dis=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]==s2[i])
                ++dis;
        }
        return dis;
    }
    vector<vector<string > > findLadders(string start, string end, unordered_set<string> &dict) {
        //int d=start.length();
        vector<vector<string > > s;
        unordered_set<string > us=dict;
        for(auto it=us.begin();it!=us.end();it++){
            if(dist(*it,start)==1){
                vector<string > vs;
                vs.push_back(start);
                vs.push_back(*it);
                s.push_back(vs);
                us.erase(it);
            }
        }
        bool flag=false;
        while(us.size()!=0){
            for(vector<vector<string > >::iterator it1=s.begin();it1!=s.end();it++){
                if(dist(end,*((*it1).end())==1)){
                    (*it1).push_back(end);
                    flag=true;
                }
                else{
                    for(auto usIt=us.begin();usIt!=us.end();usIt++){
                        if(dist(*usIt,*((*it1).end()))==1){
                            vector<string > toInsert=*it1;
                            toInsert.push_back(*usIt);
                            us.erase(usIt);
                        }
                    }
                    s.erase(it1);
                }
            }
            if(flag==true)
                break;
        }
        vector<vector<string > > result;
        for(vector<vector<string > >::iterator it2=s.begin();it2!=s.end();it2++){
            if(*((*it).end())==end){
                result.push_back(it2);
            }
        }
        return result;
    }
};

int main ()
{
    Solution s;
    unordered_set<string > myset = {"hot","dot","dog","lot","log"};
    start="hit";
    end="cog";
    vector<vector<string > > r=s.findLadders(start,end,myset);
    for(vector<vector<string > >::iterator itRe=r.begin();itRe!=r.end();itRe++){
        for(vector<string >::iterator itR=(*itRe).begin();itR!=(*itRe).end();itR++){
            cout<<*itR<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
