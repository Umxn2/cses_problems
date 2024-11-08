#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
    long long len;
    cin>>len;
    long long value;
    cin>>value;
    vector<long long> arr(len);
    for(long long i = 0;i<len;i++){
        cin>>arr[i];
    }
    unordered_map<long long, long long> um;
    long long l = 0;
    long long r = 0;
    long long count = 0;
    long long size = 0;
    while(r<len){
        if(um.find(arr[r])!=um.end()){
            um[arr[r]]++;
        }
        else{
            um[arr[r]]=1;
            size++;
        }


            while(size>value){
                if(um.at(arr[l])>1){
                    um[arr[l]]--;
                }
                else{
                   um.erase(um.find(arr[l]));
                   size--;
                }
                l++;
            }
            count += (r - l + 1);

        r++;
    }
    cout<<count;
    return 0;
}
