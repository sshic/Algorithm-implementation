class Solution {
public:
    int * B;
    int binarySearch(int i,int j,int t){
        if(i>j){
            return -1;
        }
        int mid=(i+j)/2;
        if(B[mid]==t)
            return mid;
        else if(B[mid]>t)
            return binarySearch(i,mid-1,t);
        else return binarySearch(mid+1,j,t);
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        B=A;
        int pos1=-1,pos2=-1;
        pos1=pos2=binarySearch(0,n-1,target);
        while(pos1>0&&A[pos1-1]==target)
            --pos1;
        while(pos2<n-1&&A[pos2+1]==target)
            ++pos2;
        result.push_back(pos1);
        result.push_back(pos2);
        return result;
    }
};