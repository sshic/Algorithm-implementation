/*
Classic DP problem, appears in <Algorithms>
if(word1[i-1]==word2[j-1])
	dis[i,j]=min(dis[i-1][j-1],dis[i-1][j]+1,dis[i][j-1]+1);
else
	dis[i,j]=min(dis[i-1][j-1]+1,dis[i-1][j]+1,dis[i][j-1]+1);
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.length(),len2=word2.length();
        int dis[1000][1000];
        int i,j;
        for(i=0;i<=len2;i++){
            dis[0][i]=i;
        }
        for(i=0;i<=len1;i++){
            dis[i][0]=i;
        }
        for(i=1;i<=len1;i++){
            for(j=1;j<=len2;j++){
                if(word1[i-1]==word2[j-1]){
                    dis[i][j]=min(dis[i-1][j-1],dis[i-1][j]+1);
                    dis[i][j]=min(dis[i][j],dis[i][j-1]+1);
                }
                else{
                    dis[i][j]=min(dis[i-1][j-1]+1,dis[i-1][j]+1);
                    dis[i][j]=min(dis[i][j],dis[i][j-1]+1);
                }
            }
        }
        return dis[len1][len2];
    }
};