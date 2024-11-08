#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
int main(){
    int num;
    cin>>num;
    vector<long long> arr(num);
    for(int i = 0;i<num;i++){
        cin>>arr[i];
    }
    int n = arr.size();
    sort(arr.begin(), arr.end());
    long long sum = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] > sum+1){
            cout << sum + 1 << "\n";
            return 0;
        }
        sum += arr[i];
    }
    cout << sum + 1 << "\n";
    return 0;

}
