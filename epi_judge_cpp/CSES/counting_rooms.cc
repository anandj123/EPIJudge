#include <bits/stdc++.h>
using namespace std;
void dfs(vector<string>& rows, int row, int col, int n, int m){
    rows[row][col] = '#';
    if (row>0 && rows[row-1][col] == '.') dfs(rows,row-1,col,n,m);
    if (row<n-1 && rows[row+1][col] == '.') dfs(rows,row+1,col,n,m);
    if (col >0 && rows[row][col-1] == '.') dfs(rows,row,col-1,n,m);
    if (col<m-1 && rows[row][col+1] == '.') dfs(rows,row,col+1,n,m);
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<string> rows(n);
    for(int i=0;i<n;++i) cin >> rows[i];
    int nroom = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if (rows[i][j]=='.') {
                ++nroom;
                dfs(rows,i,j, n, m);
            }
        }
    }
    cout << nroom << endl;
}