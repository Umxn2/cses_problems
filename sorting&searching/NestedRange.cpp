#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;
class comparator {
    vector<vector<int> >& sum;
public:
    comparator(vector<vector<int> >& Sum) : sum(Sum) {}

    bool operator()(int first, int second) const {
        return std::abs(sum[first][0] - sum[first][1]) < std::abs(sum[second][0] - sum[second][1]);
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int> > nums(n + 1);

    for (int i = 1; i <= n; i++) {
        vector<int> temp(2);
        cin >> temp[0];
        cin >> temp[1];
        nums[i] = temp;
    }
    comparator s(nums);
    unordered_map<int, set<int, comparator> > um;
    return 0;
}
