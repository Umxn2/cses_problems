#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
long long converInto(vector<int> &arr, int len){
    long long sum = 0;
    for(auto it: arr){
       sum+=abs(it-len);
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr (n);
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        mini = min(arr[i], mini);
        maxi = max(arr[i], maxi);
    }
    int l = mini;
    int r = maxi;
    while(l<=r){
        int mid = (r-l)/2+l;
        if(converInto(arr, mid)<=converInto(arr, mid-1)&&converInto(arr, mid)<=converInto(arr, mid+1)){
            cout<<converInto(arr, mid);
            return 0;
        }
        else if(converInto(arr,mid)<converInto(arr,mid+1)){
            r=mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return 0;
}
