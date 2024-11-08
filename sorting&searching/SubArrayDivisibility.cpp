#include <iostream>
#include <unordered_set>
#include <vector>
#include <map>
using namespace std;
int main(){
    int len;
    cin>> len;
    vector<int> nums(len);
    for(int i = 0;i<len;i++){
        cin>>nums[i];
    }
    map<long long, long long> prefix;
    prefix[0]=1;
    long long count = 0;
    long long sum = 0;
    for(int i = 0;i<len;i++){
        sum+=nums[i];
        int rem = sum % len;

                // Adjust for negative remainders
        if (rem < 0) {
            rem += len;
        }
        if(prefix.find(rem)!=prefix.end()){
            count+=prefix.at(rem);
            prefix[rem]++;
        }
        else{
            prefix[rem]=1;
        }
    }
    cout<<count;
    return 0;

}
