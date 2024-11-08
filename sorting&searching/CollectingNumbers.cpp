#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
  int nums;
  cin >> nums;
  vector<int> arr(nums);
  for (int i = 0; i < nums; i++) {
    cin >> arr[i];
  }
  int count = 0;
  set<int> s;
  for (auto it : arr) {
    if (s.find(it - 1) == s.end()) {
      count++;
      s.insert(it);

    } else {
      auto at = s.find(it - 1);
      s.erase(at);
      s.insert(it);
    }
  }
  cout << count;
  return 0;
}
