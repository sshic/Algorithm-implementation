//leetcode Palindrome
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
	int p_table[1000][1000];
	vector<vector<string > > v_v_str;
	int len;
	string s_copy;
	vector<string > v_str;
	void dfs(int l){
		if(l==len){
			v_v_str.push_back(v_str);
			return;
		}
		for(int i=l;i<len;i++){
			if(p_table[l][i]==1){
				string str=s_copy.substr(l,i-l+1);
				v_str.push_back(str);
				dfs(i+1);
				v_str.pop_back();
			}
		}
	}

	vector<vector<string > > partition(string s) {
		memset(p_table,0,sizeof(p_table));
		len=s.size();
		s_copy=s;
		v_v_str.clear();
		v_str.clear();
		for(int i=0;i<len;i++)
		{
			for(int j=i;j<len;j++){
				bool is_p=true;
				int t1=i,t2=j;
				while(t1<t2){
					if(s[t1]!=s[t2])
					{
						is_p=false;
						break;
					}
					++t1;
					--t2;
				}
				if(is_p==true)
					p_table[i][j]=1;
			}
		}
		dfs(0);
		return v_v_str;
	}
};

int main(){
	Solution sol;
	vector<vector<string > > result;
	result=sol.partition("ab");
	for(vector<vector<string > >::iterator i=result.begin();i!=result.end();i++)
    {
        for(vector<string >::iterator j=(*i).begin();j!=(*i).end();j++)
            cout<<*j<<" ";
        cout<<endl;
    }
	return 0;
}
