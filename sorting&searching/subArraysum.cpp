#include <iostream>
#include <vector>
using namespace std;
int main(){
    int len;
    cin>>len;
    int target;
    cin>> target;
    vector<int> nums(len);
    for(int i = 0;i<len;i++){
        cin>>nums[i];
    }
    int l = 0;
    int r = 0;
    int count = 0;
    int sum = 0;
    while(r<len &&l<len){

        sum+=nums[r];
        if(sum==target){
            count++;
            r++;
            continue;
        }
        if(sum>target){
            while(sum>target && l<len){
                sum-=nums[l];
                l++;
            }
            if(sum==target){
                count++;
            }
        }
       r++;
    }
    cout<<count;
    return 0;
}
