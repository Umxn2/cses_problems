#include <iostream>
#include <vector>
using namespace std;
bool checkIfPossible(long long hour, vector<long long> &workingTimes, long long numOfProducts){
    long long productsMade = 0;
    for(long long it : workingTimes){
        long long div = hour/it;
        productsMade+=div;
        if (productsMade >= numOfProducts) {
                  return true;
              }
    }
    if(productsMade>=numOfProducts){
        return true;
    }
    return false;
}
int main(){
    //let time be t
    long long numOfMachines;
    cin>>numOfMachines;
    long long numOfProducts;
    cin>>numOfProducts;
    vector<long long> workingTimes (numOfMachines);
    long long maxTime = 0;
    for(long long i = 0;i<numOfMachines;i++){
        cin>>workingTimes[i];
        maxTime = max(maxTime, workingTimes[i]);
    }
    long long l = 1;

    long long r = maxTime*numOfProducts;
    long long ans = -1;
    while(l<=r){
        long long mid = (r-l)/2+l;
        if(checkIfPossible(mid, workingTimes, numOfProducts)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<ans;
    return 0;
}
