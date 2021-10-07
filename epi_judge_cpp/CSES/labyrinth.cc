#include <bits/stdc++.h>
using namespace std;
/*
To test program run:

g++ -std=c++17 labyrinth.cc -O2 -Wall; ./a.out < test_input0.txt  


*/
struct cell{
    char direction;
    int row;
    int col;
};

std::string bfs(vector<std::string>& rows, vector<vector<char> > & path, int row, int col, int n, int m){
    queue<cell> q;
    q.push({'A',row,col});
    vector<char> pqueue;
    while(!q.empty()) {
        cell p = q.front();
        q.pop();
        path[p.row][p.col] = p.direction;
        if (rows[p.row][p.col] == '#') continue;
        if (rows[p.row][p.col] == 'B') {
            
            int i = p.row;
            int j = p.col;
            while(true){
                pqueue.push_back(path[i][j]);
                switch (path[i][j]){
                    case 'L':
                    j++;
                    break;
                    case 'R':
                    j--;
                    break;
                    case 'U':
                    i++;
                    break;
                    case 'D':
                    i--;
                    break;
                    default:
                    break;
                }
                if (path[i][j] == 'A') break;
            }
            
            string retVal = "";
            for(int i=pqueue.size()-1;i>=0;--i){
                retVal += pqueue[i];
            }
            return retVal;
        }
        rows[p.row][p.col] = '#';
        if(p.col>0 && rows[p.row][p.col-1] != '#') q.push({'L',p.row,p.col-1});
        if(p.col<m-1 && rows[p.row][p.col+1] != '#') q.push({'R',p.row,p.col+1});  
        if(p.row>0 && rows[p.row-1][p.col] != '#') q.push({'U',p.row-1,p.col});
        if(p.row<n-1 && rows[p.row+1][p.col] != '#') q.push({'D',p.row+1,p.col});
        
    }
    return "";
}
int main(){
    int n, m;
    cin >> n>>m;
    vector<std::string> rows(n);
    for(int i=0;i<n;++i) cin >> rows[i];
    vector< vector<char> > path(n, vector<char>(m));

    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if (rows[i][j] == 'A') {
                string ans = bfs(rows, path, i,j,n,m);
                if (ans.length() > 0) {
                    cout << "YES" << endl;
                    cout << ans.length() << endl;
                    cout << ans << endl;
                } else{
                    cout << "NO" << endl;
                }
                break;
            }
        }
    }
}