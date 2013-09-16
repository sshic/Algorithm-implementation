class Solution {
public:
	string ss;
	int len;
	vector<vector<string> > result;
	bool isPalin(string str){
		int i=0,j=str.length()-1;
		while(i<j){
			if(str[i]!=str[j])
                return false;
			++i;--j;
		}
		return true;
	}

	void dfs(vector<string> v,int pos){
		if(pos==len){
			result.push_back(v);
			return;
		}
		string str;
		for(int j=1;j<=len-pos;j++){
			str=ss.substr(pos,j);
			if(isPalin(str)){
				v.push_back(str);
				dfs(v,pos+j);
				v.pop_back();
			}
		}
		return;
	}

	vector<vector<string> > partition(string s) {
		ss=s;
		len=s.length();
		result.clear();
		vector<string> str;
		dfs(str,0);
		return result;
	}
};