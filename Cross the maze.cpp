#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    freopen("test_in.txt","r",stdin);
    FILE *fp=fopen("Moist.out","w");
    int num,n,step;
    string str;
    int sx,sy,ex,ey;
    bool flag;
    cin>>num;
    char dir[4]={'S','E','N','W'};
    vector<vector<int> > increase={{1,0},{0,1},{-1,0},{0,-1}};
    for(int i=1;i<=num;i++){
        cin>>n;
        step=0;
        flag=true;
        vector<string> maze;
        string tmp="",t;
        for(int j=0;j<=n+1;j++)
            tmp+='#';
        maze.push_back(tmp);
        for(int j=0;j<n;j++){
            t="#";
            cin>>str;
            t+=str;
            t+='#';
            maze.push_back(t);
        }
        maze.push_back(tmp);

        cin>>sx>>sy>>ex>>ey;
        str="";
        int d;
        if(sx==sy&&sx==1)
            d=1;
        else if(sx==sy&&sx==n)
            d=3;
        else if(sx!=sy&&sx==1)
            d=0;
        else if(sx!=sy&&sx==n)
            d=2;

        int curx=sx,cury=sy;
        while(curx!=ex||cury!=ey){
            if(maze[curx+increase[(d+1)%4][0]][cury+increase[(d+1)%4][1]]!='#')
                d=(d+1)%4;
            else if(maze[curx+increase[d][0]][cury+increase[d][1]]=='#'){
                int cnt=0;
                while(maze[curx+increase[d][0]][cury+increase[d][1]]=='#'&&cnt<4){
                    d=((d-1)+4)%4;
                    ++cnt;
                }
                if(cnt>=4){
                    flag=false;
                    break;
                }
            }
            str+=dir[d];
            ++step;
            curx+=increase[d][0];
            cury+=increase[d][1];
            if(step>10000){
                flag=false;
                break;
            }
        }
        fputs("Case #",fp);
        fprintf(fp,"%d",i);
        fputs(": ",fp);
        if(flag){
            fprintf(fp,"%d\n",step);
            fprintf(fp,"%s\n",str.c_str());
        }
        else
            fputs("Edison ran out of energy.\n",fp);
    }
    return 0;
}
