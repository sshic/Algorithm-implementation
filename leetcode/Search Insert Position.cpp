class Solution {public:    int searchInsert(int A[], int n, int target) {        int i;        for(i=0;i<n;i++){            if(A[i]>target)                break;        }        if(i==n-1&&A[i]<target)            return n;        else if(i==n-1&&A[i]==target)            return n-1;        else if(i-1<0||A[i-1]!=target)            return i;        else return i-1;    }};