#include <iostream>
#include <sys/wait.h>
#include <vector>
using namespace std;
void dfs(int x, int y, vector<vector<char>> &visitedArr, vector<int> &xdir,
         vector<int> &ydir, int &height, int &width, vector<string> &map) {
  if (visitedArr[x][y] != '*') {
    return;
  }
  visitedArr[x][y] = '#';
  for (int i = 0; i < 4; i++) {
    int newX = x + xdir[i];
    int newY = y + ydir[i];
    if (newX < height && newX >= 0 && newY >= 0 && newY < width) {
      if (map[newX][newY] == '.') {
        dfs(newX, newY, visitedArr, xdir, ydir, height, width, map);
      }
    }
  }
}
int main() {
  int height;
  cin >> height;
  int width;
  cin >> width;
  vector<string> map(height);
  vector<vector<char>> visitedArr(height, vector<char>(width, '*'));
  for (int i = 0; i < height; i++) {
    cin >> map[i];
  }
  vector<int> ydir = {0, 1, 0, -1};
  vector<int> xdir = {-1, 0, 1, 0};
  int count = 0;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (map[i][j] == '.' && visitedArr[i][j] == '*') {
        count++;
        dfs(i, j, visitedArr, xdir, ydir, height, width, map);
      }
    }
  }

  cout << count;
  return 0;
}
