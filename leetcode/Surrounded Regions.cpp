
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int row,column;
	void search(vector<vector<char > >& board,int i,int j){
		board[i][j] = 'F';
		if(i+1<row && board[i+1][j]=='O')
			search(board,i+1,j);
		if(i-1>=0 && board[i-1][j]=='O')
			search(board,i-1,j);
        if(j+1<column && board[i][j+1]=='O')
            search(board,i,j+1);
        if(j-1>=0 && board[i][j-1]=='O')
			search(board,i,j-1);
	}
    void solve(vector<vector<char > > &board) {
        if(board.empty())
            return;
		row = board.size();
		column = board[0].size();
		for(int i=0;i<column;i++){
			if(board[0][i]=='O'){
				search(board,0,i);
			}
		}
		for(int i=0;i<column;i++){
			if(board[row-1][i]=='O')
				search(board,row-1,i);
		}
		for(int i=0;i<row;i++){
			if(board[i][0]=='O')
				search(board,i,0);
		}
		for(int i=0;i<row;i++){
			if(board[i][column-1]=='O')
				search(board,i,column-1);
		}
		for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='F')
                    board[i][j]='O';
            }
		}
	}
};


int main(){
    Solution sol;
   // X X X X
   // X O O X
   // X X O X
   // X O X X
    vector<vector<char > > b;
    vector<char> v;
    v.push_back('X');
    v.push_back('O');
    v.push_back('X');
  //  v.push_back('X');
    b.push_back(v);
    v.clear();
   // v.push_back('X');
    v.push_back('O');
    v.push_back('X');
    v.push_back('O');
    b.push_back(v);
    v.clear();
  //  v.push_back('X');
    v.push_back('X');
    v.push_back('O');
    v.push_back('X');
    b.push_back(v);
    v.clear();
 //   v.push_back('X');
 //   v.push_back('O');
//    v.push_back('X');
  //  v.push_back('X');
  //  b.push_back(v);
 //   v.clear();
    for(vector<vector<char > >::iterator i=b.begin();i!=b.end();i++)
    {
        for(vector<char >::iterator j=(*i).begin();j!=(*i).end();j++)
            cout<<*j<<" ";
        cout<<endl;
    }
    sol.solve(b);
    cout<<"==================="<<endl;
    for(vector<vector<char > >::iterator i=b.begin();i!=b.end();i++)
    {
        for(vector<char >::iterator j=(*i).begin();j!=(*i).end();j++)
            cout<<*j<<" ";
        cout<<endl;
    }
    return 0;
}
