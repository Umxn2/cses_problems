#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int numofchildren;
    cin>>numofchildren;
    int maxWeight;
    cin>>maxWeight;
    vector<int> weights(numofchildren);
    for(int i = 0;i<numofchildren;i++){
        cin>>weights[i];
    }
    sort(weights.begin(), weights.end());
    int numOfgondola = 0;
    int l = 0;
    int r = numofchildren-1;
    while(l<=r){
        if((weights[l]+weights[r])<=maxWeight){
            numOfgondola++;
            l++;
            r--;
        }
        else{
            r--;
            numOfgondola++;
        }
    }
    cout<<numOfgondola;
    return 0;
}
