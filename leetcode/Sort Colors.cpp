//Insert Sort
class Solution {
public:
    void sortColors(int A[], int n) {
        int t;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(A[i]>=A[j])
                    break;
            }
            t=A[i];
            for(int k=i-1;k>j;k--){
                A[k+1]=A[k]
            }
            A[j+1]=t;
        }
    }
};