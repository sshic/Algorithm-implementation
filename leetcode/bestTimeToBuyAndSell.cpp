class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size<=1)
            return 0;
        int min1=0,min2=0;
        int tmp=0,i=0,j=0;
        while(j<prices.size()){
            while(j+1<prices.size()&&prices[j+1]<=prices[j]){
                ++j;
                ++i;
            }
            while((j+1)<prices.size()&&prices[j+1]>prices[j]){
                tmp=prices[++j]-prices[i];
                if(tmp>min1){
                    min1=tmp;
                }
                else if(tmp>min2)
                    min2=tmp;
            }
            i=j;
        }
        return min1+min2;
    }
};
