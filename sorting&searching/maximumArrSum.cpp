#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main(){
    int nums;
    cin>>nums;
    vector<int> arr (nums);
    for(int i = 0;i<nums;i++){
        cin>>arr[i];
    }
    int r = 0;
    long long maxSum = INT_MIN;
    long long sum = 0;
    while(r<nums){
        sum+=arr[r];
        maxSum = max(maxSum, sum);
        if(sum<0){
            sum = 0;
        }
        r++;
    }
    cout<<maxSum;
    return 0;
}
