class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if(matrix.size()==0)
            return result;
        int m=matrix.size();
        int n=matrix[0].size();
        int t=min(m,n);
        for(int i=0;i<(t+1)/2;i++){
            if(2*i+1==m||2*i+1==n){
                if(m<n){
                    for(int j=i;j<=n-i-1;j++){
                        result.push_back(matrix[i][j]);
                    }
                }
                else{
                    for(int j=i;j<=m-i-1;j++){
                        result.push_back(matrix[j][i]);
                    }
                }
                return result;
            }

            for(int j=i;j<=n-i-1;j++){
                result.push_back(matrix[i][j]);
            }
            for(int j=i+1;j<=m-i-1;j++){
                result.push_back(matrix[j][n-i-1]);
            }
            for(int j=n-i-2;j>i;j--){
                result.push_back(matrix[m-i-1][j]);
            }
            for(int j=m-i-1;j>i;j--){
                result.push_back(matrix[j][i]);
            }
        }
        return result;
    }
};
