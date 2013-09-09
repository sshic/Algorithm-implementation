class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        for(int i=0;i<n;i++){
            if(A[i]==elem){
                for(int j=i;j<n-1;j++)
                    A[j]=A[j+1];
                --n;
                --i;
            }
        }
        return n;
    }
};