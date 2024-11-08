#include <iostream>
#include <vector>
using namespace std;
int main() {
  long long mod = 1e9 + 7;
  int n;
  cin >> n;
  vector<long long> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      if ((i - j) >= 0) {
        dp[i] += dp[i - j];
        dp[i] = dp[i] % mod;
      }
    }
  }
  long long ans = dp[n];
  cout << ans;
  return 0;
}
