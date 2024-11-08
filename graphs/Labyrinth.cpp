#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int height;
    cin >> height;
    int width;
    cin >> width;

    vector<string> map(height);
    vector<vector<char> > visitedArr(height, vector<char>(width, '*'));
    vector<vector<char> > direction(height, vector<char>(width, '#'));

    int startX, startY;
    for(int i = 0; i < height; i++) {
          for(int j = 0; j < width; j++) {
              char ch;
              cin >> ch;
              map[i] += ch;
              if(ch == 'A') {
                  startX = j;
                  startY = i;
              }
          }
      }

    vector<int> ydir = {0, 1, 0, -1};
    vector<int> xdir = {-1, 0, 1, 0};
    vector<char> dirs = {'L', 'D', 'R', 'U'};
    string ans = "";

    queue<pair<int, int> > q;
    q.push({startY, startX});
    visitedArr[startY][startX] = '#';

    int count = 0;

    while(!q.empty()) {
        int len = q.size();
        for(int i = 0; i < len; i++) {
            pair<int, int> top = q.front();
            q.pop();

            for(int j = 0; j < 4; j++) {
                int newY = top.first + ydir[j];
                int newX = top.second + xdir[j];

                if(newY >= 0 && newY < height && newX >= 0 && newX < width) {
                    if(map[newY][newX]=='B') {
                        cout << "YES" << endl;
                        cout << count + 1 << endl;
                        direction[newY][newX]=dirs[j];
                        string path = "";
                        while (newX != startX || newY != startY) {
                            path += direction[newY][newX];
                            int dir = find(dirs.begin(), dirs.end(), direction[newY][newX]) - dirs.begin();
                            newX -= xdir[dir];
                            newY -= ydir[dir];
                        }
                        reverse(path.begin(), path.end());
                        cout<<path<<endl;
                        return 0;
                    }
                    if(visitedArr[newY][newX] == '*' && map[newY][newX] == '.') {
                        visitedArr[newY][newX] = '#';
                        direction[newY][newX] = dirs[j];
                        q.push({newY, newX});
                    }
                }
            }
        }
        count++;
    }
    cout << "NO";
    return 0;
}
