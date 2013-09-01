class Solution {
public:
    bool canJump(int A[], int n) {
        if(n<=1)
            return true;
        if(A[0]==0)
            return false;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (i > curr) {
                return false;
            }
            curr = max(curr, i+A[i]);
        }
        return true;
    }
};