#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int find(vector<char> &dirs, char ch){
    for(int i = 0;i<dirs.size();i++){
        if(ch==dirs[i]){
            return i;
        }
    }
    return -1;
}
int main(){
    int rows;
    cin>> rows;
    int cols;
    cin>>cols;
    vector<vector<char> > map (rows, vector<char> (cols));
    vector<vector<char> > usablecells (rows, vector<char> (cols, '*'));
    vector<vector<char> > directions (rows, vector<char> (cols, '.'));

    int startrow;
    int startcol;
    vector<pair<int, int> > monster;
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            cin>>map[i][j];
            if(map[i][j]=='A'){
                startrow=i;
                startcol = j;
                usablecells[i][j]='/';
                if(startrow==0||startrow==rows-1|| startcol==0 || startcol==cols-1){
                    cout<<"YES"<<endl;
                    cout<<0;
                    return 0;
                }
            }
            if(map[i][j]=='M'){
               monster.push_back({i,j});
               usablecells[i][j]='#';
            }
        }
    }
queue<pair<pair<int,int>, char> > q;
for(auto it: monster){
    q.push({it,'M'});
}
q.push({{startrow, startcol},'P'});
vector<int> rowdir = {0, 1, 0, -1};
vector<int> coldir = {-1, 0, 1, 0};
vector<char> dirs = {'L', 'D', 'R', 'U'};
while (!q.empty()) {
    int len = q.size();
    for(int i = 0;i<len;i++){
        auto top = q.front();
        q.pop();
        for(int j = 0;j<4;j++){
            int newRow = top.first.first+rowdir[j];
            int newCol = top.first.second+coldir[j];
            if(newCol>=0&& newCol<cols&& newRow>=0 && newRow<rows){
                if(top.second=='M'&&usablecells[newRow][newCol]!='#'&&map[newRow][newCol]=='.'){
                    usablecells[newRow][newCol]='#';
                    q.push({{newRow, newCol},'M'});
                }
                else if(top.second=='P'&&usablecells[newRow][newCol]=='*'&&map[newRow][newCol]=='.'){
                    usablecells[newRow][newCol]='/';
                    q.push({{newRow, newCol},'P'});
                    directions[newRow][newCol]=dirs[j];
                    if(newRow==0||newRow==rows-1|| newCol==0 || newCol==cols-1){
                        string path = "";
                        int dirRow = newRow;
                        int dirCol = newCol;
                        while(dirRow!=startrow || dirCol!=startcol){
                            path+=directions[dirRow][dirCol];
                            int dirIndex = find(dirs, directions[dirRow][dirCol]);
                            dirRow-=rowdir[dirIndex];
                            dirCol-=coldir[dirIndex];
                        }
                        reverse(path.begin(), path.end());
                        cout<<"YES"<<endl;
                        cout<<path.size()<<endl;
                        for(auto it: path){
                            cout<<it;
                        }
                        return 0;
                    }
                }
            }
        }
    }
}
cout<<"NO";
return 0;
}
