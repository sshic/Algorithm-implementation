#52 mili secs for large data set

class Solution {
public:
    int trap(int A[], int n) {
        int p1=0,result=0;
        vector<int> highPoint;
        while(p1<n&&A[p1]<=A[p1+1])
            ++p1;
        highPoint.push_back(p1);
        int m=n-1;
        while(A[m]<=A[m-1])
            --m;
        while(p1<m){
            while(p1<m&&A[p1+1]<=A[p1])
                ++p1;
            while(p1<m&&A[p1+1]>=A[p1])
                ++p1;
            highPoint.push_back(p1);
        }

        int cur=0,big;
        for(int i=0;i<highPoint.size()-1;i++){
            if(A[highPoint[i]]<=A[highPoint[i+1]]){
                for(int j=highPoint[i]+1;j<highPoint[i+1];j++){
                    if(A[highPoint[i]]>A[j])
                        result+=A[highPoint[i]]-A[j];
                }
            }
            else{
                cur=i;
                big=i+1;
                while(i+1<highPoint.size()&&A[highPoint[i+1]]<A[highPoint[cur]]){
                    if(A[highPoint[i+1]]>A[highPoint[big]])
                        big=i+1;
                    ++i;
                }
                if(i+1<highPoint.size()){
                    ++i;
                    big=i;
                }
               // cout<<cur<<"big "<<big<<endl;
                int cnt=A[highPoint[cur]]>A[highPoint[big]]? A[highPoint[big]]:A[highPoint[cur]];
                for(int j=highPoint[cur]+1;j<highPoint[big];j++)
                    if(cnt>A[j])
                        result+=cnt-A[j];
                i=--big;
            }
        }
        return result;
    }
};
