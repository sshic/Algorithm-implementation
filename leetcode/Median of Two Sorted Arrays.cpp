#192 mili secs for large data set#http://www2.myoops.org/course_material/mit/NR/rdonlyres/Electrical-Engineering-and-Computer-Science/6-046JFall-2005/30C68118-E436-#4FE3-8C79-6BAFBB07D935/0/ps9sol.pdfclass Solution {public:    int num;    int numA,numB;    double findMedian(int A[],int B[],int left,int right){        if(left>right){            swap(numA,numB);            return findMedian(B,A,max(1,(num+1)/2-numB),min(numA,(num+1)/2));        }        int i=(left+right)/2;        int j=(num+1)/2-i;        if((j==0||A[i-1]>=B[j-1])&&(j==numB||A[i-1]<=B[j])){            if(num%2==1)                return A[i-1];            else{                int t;                if(j==numB&&i!=numA)                    return (double)(A[i-1]+A[i])/2;                else if(i==numA&&j!=numB)                    return (double)(A[i-1]+B[j])/2;                else{                    t=min(A[i],B[j]);                    return (double)(A[i-1]+t)/2;                }            }        }        else if((j==0||A[i-1]>B[j-1])&&(j!=numB)&&(A[i-1]>B[j]))            return findMedian(A,B,left,i-1);        else return findMedian(A,B,i+1,right);    }    double findMedianSortedArrays(int A[], int m, int B[], int n) {        int left,right;        num=m+n;        numA=m;numB=n;        left=max(1,(num+1)/2-n);        right=min((num+1)/2,m);        return findMedian(A,B,left,right);    }};