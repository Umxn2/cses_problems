#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main(){
    set<int> us;
    int num;
    cin>>num;
    vector<int> arr (num);
    for(int i = 0;i<num;i++){
        cin>>arr[i];
}
int l = 0;
int r = 0;
int count= 0;
int maxCount = 0;
while(r<num){
    if(us.find(arr[r])==us.end()){
        us.insert(arr[r]);
        count++;
        maxCount= max(maxCount, count);
    }
    else{
        while(arr[l]!=arr[r]){
            auto at = us.find(arr[l]);
            us.erase(at);
            count--;
            l++;
        }
        l++;
    }
     r++;
}
cout<<maxCount;
return 0;
}
