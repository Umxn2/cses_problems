#include <iostream>
#include <vector>
using namespace std;
int findUpperBound(vector<int> &heads, int num){
    int l = 0;
    int size = heads.size();
    int r = size -1;
    int ans = -1;
    while(l<=r){
        int mid = (r-l)/2+l;
        if(heads[mid]<=num){
            l=mid+1;
        }
        else{
            ans = mid;
            r = mid-1;
        }

    }
    return ans;
}
int main(){
    int num;
    cin>>num;
    vector<int> arr (num) ;
    for(int i = 0;i<num;i++){
        cin>>arr[i];
    }
    vector<int> heads;
    heads.push_back(arr[0]);
    for(int i = 1;i<num;i++){
        int a = findUpperBound(heads, arr[i]);
        if(a==-1){
            heads.push_back(arr[i]);
        }
        else{
            heads[a]=arr[i];
        }
    }
    cout<<heads.size();
    return 0;
}
