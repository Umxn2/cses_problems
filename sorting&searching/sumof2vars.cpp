#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
    int num;
    cin>>num;
    int target;
    cin>>target;
    vector<int> arr (num);
    map<int, int> um;
    for(int i = 0;i<num;i++){
        cin>>arr[i];

        if(um.find(target-arr[i])!=um.end()){
            int l = min(i,um[target-arr[i]])+1;
            int r = max(i,um[target-arr[i]])+1;
            cout<<l<<" "<<r;
            return 0;
        }
        um[arr[i]]=i;
    }
    cout<<"IMPOSSIBLE";

    return 0;
}
