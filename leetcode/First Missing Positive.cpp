#20 mili secs for large data set
class Solution {
public:
    int m;
    int *B;
    void s(int i,int j){
        int t=B[i];
        B[i]=B[j];
        B[j]=t;
        if(B[i]>0&&B[i]<=m&&B[i]!=i+1&&B[B[i]-1]!=B[i])
            s(i,B[i]-1);
        return;
    }
    int firstMissingPositive(int A[], int n) {
        m=n;
        B=A;
        for(int i=0;i<n;i++){
            if(A[i]>0&&A[i]<=n&&A[i]!=i+1&&A[A[i]-1]!=A[i])
                s(i,A[i]-1);
        }
        for(int i=0;i<n;i++){
            if(A[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};