#76 mili secs for large data set

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size()<=1)
            return;
        int i,j;
        for(i=num.size()-2;i>=0;i--){
            if(num[i]<num[i+1])
                break;
        }
        if(i<0){
            sort(num.begin(),num.end());
            return;
        }

        for(j=num.size()-1;j>i;j--){
            if(num[j]>num[i])
                break;
        }
        swap(num[i],num[j]);
        sort(num.begin()+i+1,num.end());
        return;
    }
};