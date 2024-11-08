#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(vector<int> first, vector<int> second){
    if(first[0]<second[0]){
        return true;
    }
    if(first[0]==second[0]){
        if(first[1]>second[1]){
            return true;
        }
    }
    return false;
}
int main(){
    int nums;
    cin>>nums;
    vector<vector<int> > store (nums, vector<int> (2));
    for(int i = 0;i<nums;i++){
        cin>>store[i][0];
        cin>>store[i][1];
    }
    sort(store.begin(), store.end(), compare);
    long long currTime = 0;
    long long reward = 0;
    for(auto it: store){
        reward += it[1]-it[0]-currTime;
        currTime += it[0];
    }
    cout<<reward;
    return 0;
}
