class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] > target) {
                if (A[left] <= target)
                    right = mid - 1;
                else {
                    if (A[right] > A[mid])
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
            }
            else if (A[mid] < target) {
                if (A[right] >= target)
                    left = mid + 1;
                else {
                    if (A[left] > A[mid])
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
            }
            else
                return mid;
        }
        
        return -1;
    }
};