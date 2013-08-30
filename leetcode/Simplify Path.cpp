class Solution {
public:
    string simplifyPath(string path) {
        int back_dir=0,cnt=0;
        vector<string> p;
        if(path[path.length()-1]!='/')
            path+="/";
        while(cnt<path.length()){
            int i=path.find_first_not_of("/",cnt);
            if(i==string::npos){
                i=path.length();
                break;
            }
            int j=path.find_first_of("/",i);
            string str=path.substr(i,j-i);
            if(str!="."){
                if(str==".."&&p.size()!=0)
                    p.pop_back();
                else if(str!="..")
                    p.push_back(str);
            }
            cnt=j;
        }
                string result="/";;
        if(p.size()==0)
            return result;
        else{
            for(int i=0;i<p.size()-1;i++){
                result+=p[i];
                result+="/";
            }
            result+=p[p.size()-1];
            return result;
        }
    }
};